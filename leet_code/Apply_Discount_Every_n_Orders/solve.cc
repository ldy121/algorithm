class Cashier {
private :
	unordered_map<int, int> m_price;
	int m_discount_rate;
	int m_discount_customer;
	int m_customer;
public:
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
		m_customer = 0;
		m_discount_customer = n;
		m_discount_rate = discount;

		for (int i = 0; i < products.size(); ++i) {
			m_price[products[i]] = prices[i];
		}
	}

	double getBill(vector<int> product, vector<int> amount) {
		double ret = 0.0;
		long long total_price = 0;

		for (int i = 0; i < product.size(); ++i) {
			total_price += m_price[product[i]] * amount[i];
		}
		if (++m_customer == m_discount_customer) {
			total_price = total_price * (100 - m_discount_rate);
			ret = (double)total_price / 100.f;
		} else {
			ret = total_price;
		}

		m_customer %= m_discount_customer;

		return ret;
	}
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
