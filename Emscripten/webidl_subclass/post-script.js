__ATPOSTRUN__.push(() => {
	var _t = new ImplXClass();
	_t.virtualFunc = function(x) {
		return 2 * x;
	};
	console.log(_t.runVirtualFunc(_t, 10));
});
