__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	console.log(_t.get_x());
	_t.set_x(11);
	console.log(_t.get_x());
	Module.destroy(_t);
});
