__ATPOSTRUN__.push(() => {
	var xClass = new Module['xClass'](10, "Key");
	var retVector = xClass.returnVectorData();
	// 获得向量容器大小；
	var vectorSize = retVector.size();
  // 重新设置向量容器中某位置的元素；
  retVector.set(vectorSize - 1, 11);
  // 从向量容器尾部推入元素；
  retVector.push_back(12);
  // 遍历向量容器值；
  for (var i = 0; i < retVector.size(); i++) {
  	console.log("Vector Value: ", retVector.get(i));
  }
  // 扩增向量容器并设置默认值；
  retVector.resize(20, 1);

  var retMap = xClass.returnMapData();
  // 获得字典容器大小；
  var mapSize = retMap.size();
  // 遍历字典容器某索引位置的值；
  console.log("Map Value: ", retMap.get(10));
  // 重新设置字典容器某索引位置的值；
  retMap.set(10, "OtherKey");

  xClass.delete()
});
