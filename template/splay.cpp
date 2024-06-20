template<class T>
class splay_tree {
	struct node;
public:
	typedef node* pnode;

private:
	struct node {

		T value;
		pnode parent, child[2];

		node() {
			parent = child[0] = child[1] = 0;
		}
		node(T value_) : value(value_) {
			parent = child[0] = child[1] = 0;
		}

		void add_child(pnode c, bool side) {
			child[side] = c;
			if(c) {
				c->parent = this;
			}
		}
		void del_child(bool side) {
			if(child[side]) {
				child[side]->parent = 0;	
				child[side] = 0;
			}
		}
		bool side() {
			assert(parent);
			return parent->child[1] == this;
		}

		void rotate() {
			assert(parent);
			bool right = !side();
			const pnode p = parent, g = p->parent;
			if(g) {
				g->add_child(this, p->side());
			}
			else {
				parent = 0;
			}
			p->add_child(child[right], !right);
			add_child(p, right);
		}

		void splay() {
			for(; parent; rotate()) {
				if(parent->parent) {
					(side() == parent->side() ? parent : this)->rotate();
				}
			}
		}

		pnode split() {
			splay();
			pnode ret = new node[2];
			ret[0] = this;
			ret[1] = child[1];
			del_child(1);
			return ret;
		}	
		
		pnode minimum() {
			pnode ret = this;
			while(ret->child[0]) {
				ret = ret->child[0];
			}
			return ret;
		}
		pnode maximum() {
			pnode ret = this;
			while(ret->child[1]) {
				ret = ret->child[1];
			}
			return ret;
		}

		pnode next() {
			pnode ret = this;
			if(ret->child[1]) {
				return ret->child[1]->minimum();
			}
			while(ret->parent && ret->side()) {
				ret = ret->parent;
			}
			return ret->parent;
		}
		pnode prev() {
			pnode ret = this;
			if(ret->child[0]) {
				return ret->child[0]->maximum();
			}
			while(ret->parent && !ret->side()) {
				ret = ret->parent;
			}
			return ret->parent;
		}
	};

	pnode root;
	size_t size_;

public:

	splay_tree() : root(0), size_(0) {}
	~splay_tree() {
		destroy(root);
	}
	void destroy(const pnode p) {
		if(p) {
			for(int i = 0; i < 2; ++i) {
				destroy(p->child[i]);
			}
			delete p;
		}
	}

	bool empty() {
		return size_ == 0;
	}
	size_t size() {
		return size_;
	}

	void insert_node(const pnode x) {
		++size_;
		if(!root) {
			root = x;
			return;
		}
		pnode y = root;
		while(1) {
			bool side = !(x->value < y->value);
			pnode c = y->child[side];
			if(!c) {
				y->add_child(x, side);
				root = x;
				x->splay();
				return;
			}
			y = c;
		}
	}
	void insert(const T& val) {
		insert_node(new node(val));
	}

	void erase_node(const pnode x) {
		assert(x);
		x->splay();
		root = join(x->child[0], x->child[1]);	
		delete x;
		--size_;
	}
	void erase(const T& val) {
		erase_node(find(val));
	}

	pnode join(const pnode a, const pnode b) {
		if(!a) {
			b->parent = 0;
			return b;
		}
		pnode mx = a->maximum();
		mx->splay();
		assert(!mx->child[1]);
		mx->add_child(b, 1);
		return mx;
	}
	pnode find(const T& val) {
		pnode x = root;
		while(x && x->value != val) {
			pnode nxt = x->child[!(val < x->value)];
			if(!nxt) {
				x->splay();
			}
			x = nxt;
		}
		return x;
	}

	pnode begin() {
		return root->minimum();
	}
	pnode end() {
		return root->maximum();
	}
};
