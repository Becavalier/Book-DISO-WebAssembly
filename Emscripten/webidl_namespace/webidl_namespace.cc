namespace WebAssembly {
	class WebIDL {
	public:
		WebIDL (int x) : x(x) {}
		int getValueXByValue (void) const {
			return x;
		}
		int x;
	};
}

