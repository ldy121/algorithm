Please use this Google doc during your interview (your interviewer will see what you write here). To free your hands for typing, we recommend using a headset or speakerphone.



Given a monochrome bitmap represented as a flat array of bytes, flip it horizontally in-place.

left_index = 8/
right_index = 32
Bitmap before reverse = [0x21, 0xF0, 0x37, 0x45, 0xAB]


[0xF0, 0xF0, 0xF0, ….., ]



void ReverseBitmap(uint8* bitmap, uint left_index, uint right_index) {
	int left = left_index / 8;		// 1
	int right = right_index / 8;	// 4

0xF0 => [3]
0x45 => [1]
	for (int i = left, j = right - 1; i < j; ++i, --j) {
		uint8 k = bitmap[i];
		bitmap[i] = bitmap[j];
		bitmap[j] = k;
	}

[0x21, 0x45, 0x37, 0xF0, 0xAB]
	for (int i = left; i < right; ++i) {
		uint j = 0;
0010 0001 0001 0000
0000 0001 0000 0010
		for (int k = 0; k < 8; ++k) {
			if (bitmap[i] & 0x1) {
				j |= 0x1;
			}
			bitmap[i] >>= 1;
			j <<= 1;
		}
		bitmap[i] = j;
	}
}

left_index, right_index are bit indices
left_index % 8 =0, right_index % 8 =0

ReverseBitmap(bitmap, 8, 32)
0x21 - 0~7
0xF0 - 

Bitmap before reverse = [0x21, 0xF0, 0x37, 0x45, 0xAB]
Bitmap after reverse = [0x21, 0xA2, 0xEC, 0x0F, 0xAB]

0x45 = 01000101
0x37 = 00110111

0xA2 = 10100010
0xEC = 11101100



2.
You are given a rooted tree consisting of N nodes. A drop of water falls on the root, and thereafter spreads down the tree by traversing node->child edges. Each edge in the tree has a different stickiness; so the water takes a different amount of time to trickle down that edge. Your aim is to find out how much time it takes for all leaves to get wet.

    root
   /(3)  \ (5)
  Node1   Node2


   root
 /(3)  \(5)
node1   node2

root = m_weight => 3, 5
       m_child => nod1, node2

class Node {
	vector<int> m_weight;
	vector<Node*> m_child;
};

int g_answer;

0 g_weight = 0
0 + 3, node1 g_answer = 0; node
0 + 5, node2 g_answer:3 5 => answer => 5

void traversal(Node* node, int weight) {
	if (weight > g_answer) {
		g_answer = w;
	}
	for (int i = 0; i < node->m_child.size(); ++i) {
		traversal(node->m_child[i], node->m_weight[i] + weight);
	}
}

int getAnswer(Node* root) {
	g_answer = 0;
	if (root == NULL) {
		return 0;
	}
	traversal(root, 0);
	return g_answer;
}






