__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	console.log(_t['returnBool']());
	console.log(_t['returnFloat']());
	console.log(_t['returnDouble']());
	console.log(_t['returnChar']());
	console.log(_t['returnString']());
	console.log(_t['returnUChar']());
	console.log(_t['returnUSInt']());
	console.log(_t['returnUShort']());
	console.log(_t['returnLong']());

	Module.destroy(_t);
});
