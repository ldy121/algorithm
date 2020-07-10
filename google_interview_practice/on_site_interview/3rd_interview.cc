Please use this Google doc during your interview (your interviewer will see what you write here). To free your hands for typing, we recommend using a headset or speakerphone.

Test
Implement delayed job queue in kernel mode (i.e. No user-mode libraries. And your code should be as efficient as possible) in C language.

register_job(func, args, clocktick);
void timer_handler()
long current_time()
struct task {
	func m_func;
	char* m_args[];
	int m_argc;
	long startTick;
};

priority_queue<task *, vector<task *>, greater> q;
spin_lock protectTaskQueue;

void registor_job(func func, char *args[], int argc, long clocktick) {
	struct task* t = malloc(sizeof(struct task));
	char *taskArgs = malloc(sizeof(char*) * argc);

	t->m_func = func;
	t->startTick = clocktick;

	for (int i = 0; i < argc; ++i) {
		int len = strlen(args[i]);
		char *sz = malloc(sizeof(char) * len);
		strcpy(sz, args[i]);
		taskArgs[i] = sz;
	}

	t->m_args = taskArgs;
	t->m_argc = argc;
	spin_lock(&protectTaskQueue);
	q.push(t);
	spin_unlock(&protectTaskQueue);
}


void timer_handler(void) {
	while(1) {
		spin_lock(&protectTaskQueue);
		bool isEmpty = q.empty();
		struct task *t = q.front();
		spin_unlock(&protectTaskQueue);

		if (isEmpty || current_time() < t->startTick) {
			break;
		}

		t->m_func(t->m_args, t->argc);

		spin_lock(&protectTaskQueue);
		q.pop();
		spin_unlock(&protectTaskQueue);

		for (int i = 0; i < t->m_argc; ++i) {
			free(t->m_argv[i]);
		}
		free(t->m_argv);
		free(t);
	}
}

