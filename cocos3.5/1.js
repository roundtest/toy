window.onload=function(){
cc.game.onStart=function(){
	cc.view.adjustViewPort(true);
	cc.view.setDesignResolutionSize(320,568,cc.ResolutionPolicy.SHOW_ALL);
	cc.view.resizeWithBrowserSize(true);
	var board;
	
	var init=function(){
		var size=cc.director.getWinSize();
		var w=size.width/10;
		var h=size.height/20;
		for(var i=0;i<20;i++){
			for(var j=0;j<10;j++){
				var label=cc.LabelTTF.create("★","Courier",40);
				label.setPosition(w/2+j*w,h/2+i*h);
				label.setColor(cc.color(0,255,0));
				board.addChild(label,1);
			}
		}
	};
	
	var MyScene=cc.Scene.extend({
		onEnter:function(){
			this._super();
			board=this;
			init();
			/*var label=cc.LabelTTF.create("●☆★\n★","Courier",40);
			label.setPosition(size.width/2,size.height/2);
			this.addChild(label,1);
			console.log(label.width);
			console.log(label.height);*/
		}
	});
	
	cc.director.setDisplayStats(true);
	cc.director.runScene(new MyScene());
};
cc.game.run("gameCanvas");
};