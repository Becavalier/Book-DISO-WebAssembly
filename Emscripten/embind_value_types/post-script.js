__ATPOSTRUN__.push(() => {
  var person = Module.findPersonAtLocation([0, 0]);
	console.log('Found someone! His name is ' + person.name + ' and he is ' + person.age + ' years old!');
});
