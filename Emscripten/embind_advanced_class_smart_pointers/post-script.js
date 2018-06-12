__ATPOSTRUN__.push(() => {
	var xClass = new Module['Class'](100);  
	
  console.log(xClass['x']);
  console.log(Module['passThrough'](xClass));
  console.log(Module.getValue(Module['passToUniquePtr'](10), 'i8'));
});
