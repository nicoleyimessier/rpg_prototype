var express = require('express');
var app = express(); 
var mongojs = require('mongojs'); 
var db = mongojs('questionlist', ['questionlist']);
var bodyParser = require('body-parser');

app.use(express.static(__dirname + "/public"));
app.use(bodyParser.json());

//.get is reading
app.get('/questionlist', function (req, res){
	console.log("I received a GET request");

	db.questionlist.find(function (err, docs){
		console.log(docs);
		res.json(docs); //sends data back to controller
	});
});

//listens for request from controller
//.post is creating
app.post('/questionlist', function (req, res) {
  	console.log(req.body);
  	db.questionlist.insert(req.body, function(err, doc) {
    	res.json(doc);
  });
});

//delete
app.delete('/questionlist/:id', function (req, res) {
  var id = req.params.id;
  console.log(id);
  db.questionlist.remove({_id: mongojs.ObjectId(id)}, function (err, doc){
  	res.json(doc); //send back to controller
  });
});

//.get is reading
app.get('/questionlist/:id', function (req, res) {
  var id = req.params.id;
  console.log("reading" + id);
  db.questionlist.findOne({_id: mongojs.ObjectId(id)}, function (err, doc){
  	res.json(doc); //send back to controller
  });
});

//.put is updating 
app.put('/questionlist/:id', function (req, res) {
  var id = req.params.id;
  console.log(req.body.question);
  db.questionlist.findAndModify({query: {_id: mongojs.ObjectId(id)},
  	update: {$set: {question: req.body.question, 
  					Tokens: {
	  					Token1: 
	  						{ name: req.body.Tokens.Token1.name, yes: req.body.Tokens.Token1.yes, no: req.body.Tokens.Token1.no},
	  					Token2: 
	  						{name: req.body.Tokens.Token2.name, yes: req.body.Tokens.Token2.yes, no: req.body.Tokens.Token2.no},
						Token3: 
	  						{name: req.body.Tokens.Token3.name, yes: req.body.Tokens.Token3.yes, no: req.body.Tokens.Token3.no},
	  					Token4: 
	  						{name: req.body.Tokens.Token4.name, yes: req.body.Tokens.Token4.yes, no: req.body.Tokens.Token4.no},
						Token5: 
	  						{name: req.body.Tokens.Token5.name, yes: req.body.Tokens.Token5.yes, no: req.body.Tokens.Token5.no},
  }}},
  	new: true}, function (err, doc){
  		res.json(doc); 
  	
  });


});


app.listen(3000);
console.log("Server running on port 3000");