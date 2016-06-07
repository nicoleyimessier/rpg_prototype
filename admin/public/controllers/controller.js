var myApp = angular.module('myApp', []);

myApp.controller('AppCtrl', ['$scope', '$http', function($scope, $http) {
    console.log("Hello World from controller");

    var refresh = function() {
	    $http.get('/questionlist').success(function (response){
	    	console.log("I got the data I requested");
	    	console.log(response);
	    	$scope.questionlist = response; 
	    	$scope.questionNode = ""; //clear boxes
	    });
	}; 

	refresh();

	//add question
    $scope.addQuestion = function() {
  		console.log($scope.questionNode);
  		$http.post('/questionlist', $scope.questionNode).success(function(response) {
    		console.log(response);
    		refresh();
  		});
	};

	//remove question
	$scope.remove = function(id) {
  		console.log(id);
  		$http.delete('/questionlist/' + id).success(function(response) {
    		refresh();
  		});
	};

	//edit
	$scope.edit = function(id) {
  		console.log(id);
  		$http.get('/questionlist/' + id).success(function(response) {
    		$scope.questionNode = response;
  		});
	};


	//update
	$scope.update = function() {
  		console.log($scope.questionNode._id);
  		$http.put('/questionlist/' + $scope.questionNode._id, $scope.questionNode).success(function(response) {
    		refresh();
  		});
	};

	//-----------tokens------------
	  $scope.addToken = function() {
  		$http.get('/questionlist').success(function (response){
	    	for(var i = 0; i < response.length; i++) {
	    		console.log("updating");
	    		console.log(response[i].Tokens);
			}
			refresh(); 
	    });


	};
	


   }]);﻿