__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	console.log(_t.getValueXByValue());
	Module.destroy(_t);
});
