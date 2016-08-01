window.onresize=function(){
	var canvas = document.getElementById("testCanvas");
	//return
	//canvas.style.position="absolute";
	
	var w=window.innerWidth;//document.body.clientWidth;
	var h=window.innerHeight;//document.body.clientHeight;
	
	var scale=Math.min(w/canvas.width,h/canvas.height);
	//console.log(scale);
	canvas.style.width=Math.round(canvas.width*scale)+"px";
	canvas.style.height=Math.round(canvas.height*scale)+"px";
	console.log(canvas.style.width)
	console.log(canvas.style.height);
	//canvas.style.left=(w-(canvas.style.width))*0.5+"px";
	//canvas.style.top=(h-(canvas.style.height))*0.5+"px";
};

function init() {
	//setScreen();
	window.onresize();
	// get a reference to the canvas we'll be working with:
	var canvas = document.getElementById("testCanvas");

	// create a stage object to work with the canvas. This is the top level node in the display list:
	var stage = new createjs.Stage(canvas);
	
	var container = new createjs.Container();
	container.x = 100;
	container.y = 80;

	var target = new createjs.Shape();
	target.graphics.beginFill("#F00").drawRect(-10, -10, 300, 60).beginFill("#FFF");
	container.addChild(target);

	var txt = new createjs.Text("Double Click Me!", "36px Arial", "#FFF");
	txt.textBaseline = "top";
	container.addChild(txt);

	stage.addChild(container);

	// Create a new Text object:
	var text = new createjs.Text("☆●◎★9ello 3World!\n●●★", "36px Arial", "#777");
	text.textAlign = "left";
	
	container.on("click", function (evt) {
		text.y+=10
		//stage.update();
		//alert("Double Clicked the container object");
	});

	// add the text as a child of the stage. This means it will be drawn any time the stage is updated
	// and that its transformations will be relative to the stage coordinates:
	stage.addChild(text);

	// position the text on screen, relative to the stage coordinates:
	text.x = canvas.width / 2;
	text.y = 180;
	
	var circle = new createjs.Shape();
	circle.graphics.beginFill("DeepSkyBlue").drawCircle(0, 0, 50);
	circle.x = canvas.width/2;
	circle.y = canvas.height/2;
	stage.addChild(circle);
	
	createjs.Ticker.addEventListener("tick", stage);

	var mc = new createjs.MovieClip(null, 0, true, {start: 0, middle: 40});
	stage.addChild(mc);
	var state1 = new createjs.Shape(
			new createjs.Graphics().beginFill("#999999")
					.drawCircle(100, 200, 50));
	mc.timeline.addTween(
			createjs.Tween.get(state1)
					.to({x: 0}).to({x: 760}, 40).to({x: 0}, 40));

	mc.gotoAndPlay("middle");

	//stage.update();
}