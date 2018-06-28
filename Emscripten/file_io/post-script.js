__ATPRERUN__.push(function() {
	// set io stream;
  FS.init(function() {
    return 64; // "@"；
  }, function(text) {
    console.log('stdout', text);
  }, function(text) {
    console.log('stderr', text);
  })
});



