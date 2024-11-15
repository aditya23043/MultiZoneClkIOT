$fn=100;

radii = 1.7;
padding = 0.3;
width = 24;
height = 26.5;

border = 10;

difference(){
    cube([width+width+28+(border+2),height+10+(border+2),40]);
    translate([(border+2)/2,(border+2)/2,(border+2)/2]){
        cube([width+width+28,height+10,35]);
    }

    // screw holes
    translate([0,0,40-6]){
        translate([1.8+radii,1.8+radii,0]){
            cylinder(h=6,r=radii);
        }
        translate([width+width+28+(border+2)-radii-1.8,height+10+(border+2)-radii-1.8,0]){
            cylinder(h=6,r=radii);
        }
        translate([-1.8-radii+width+width+28+(border+2),1.8+radii,0]){
            cylinder(h=6,r=radii);
        }
        translate([1.8+radii,-1.8-radii+height+10+(border+2),0]){
            cylinder(h=6,r=radii);
        }
    }
};
