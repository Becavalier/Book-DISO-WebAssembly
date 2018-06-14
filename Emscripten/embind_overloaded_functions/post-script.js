__ATPOSTRUN__.push(() => {
	var instance = new Module['OverloadClass']();
  console.log(instance['foo_v']());
  console.log(instance['foo_i'](10));
  console.log(instance['foo_ii'](10, 10));
});
