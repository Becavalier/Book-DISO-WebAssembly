__ATPOSTRUN__.push(() => {
	var xClass = new Module['xClass'](100);
  console.log(xClass['x']);
  // 设置一个别名；
  var yClass = Module['passThrough'](xClass);
  // 修改指针所指向对象的属性值；
  yClass['x'] = 0;
  console.log(xClass['x']);
  console.log(yClass['x'])
  xClass.delete();
  yClass.delete();
});
