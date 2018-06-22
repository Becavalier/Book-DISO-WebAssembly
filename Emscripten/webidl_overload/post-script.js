__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	console.log(_t.doubleNum(2));
	Module.destroy(_t);
});
