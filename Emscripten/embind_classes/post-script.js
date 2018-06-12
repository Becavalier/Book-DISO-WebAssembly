__ATPOSTRUN__.push(() => {
	var xClass = new Module['xClass'](100, "This is a binding class!");
  console.log(xClass['x']);
  xClass['x'] = 98
  xClass.incrementX()
  console.log(xClass['x']);
  console.log(Module['xClass']['getStringValue'](xClass));
  xClass.delete()
});
