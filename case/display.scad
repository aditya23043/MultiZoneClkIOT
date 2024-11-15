$fn=100;

radii = 1.7;
padding = 0.3;
width = 24;
height = 26.5;

border = 10;

    difference(){

        union(){

            // main board
            cube([width+width+28+(border+2),height+10+(border+2),1.5]);

            translate([(width+28+(border+2))/2-2.5,(10+(border+2))/2-2.5,-4.5]){
                cube([width+5,height+5,6]);
            }
        };

        // display mounting holes
        #translate([(width+28+(border+2))/2,(10+(border+2))/2,-4.5]){
            translate([radii+padding,radii+padding,0]){
                cylinder(h=6,r=radii);
            }
            translate([width-radii-padding,height-radii-padding,0]){
                cylinder(h=6,r=radii);
            }
            translate([radii+padding,height-radii-padding,0]){
                cylinder(h=6,r=radii);
            }
            translate([width-radii-padding,radii+padding,0]){
                cylinder(h=6,r=radii);
            }
        }

        // switch 1
        translate([6+((border+2)/2),(height+10-13.9+(border+2))/2,0]){
            cube([13.9,13.9,1.5]);
        }

        // switch 2
        translate([width+width+28+(border+2)-6-5-13.9,(height+10-13.9+(border+2))/2,0]){
            cube([13.9,13.9,1.5]);
        }

        // screw holes
        translate([1.8+radii,1.8+radii,0]){
            cylinder(h=1.5,r=radii);
        }
        translate([width+width+28+(border+2)-radii-1.8,height+10+(border+2)-radii-1.8,0]){
            cylinder(h=1.5,r=radii);
        }
        translate([-1.8-radii+width+width+28+(border+2),1.8+radii,0]){
            cylinder(h=1.5,r=radii);
        }
        translate([1.8+radii,-1.8-radii+height+10+(border+2),0]){
            cylinder(h=1.5,r=radii);
        }

        // pin holes for the display
        translate([(width+28+(border+2))/2+(width/2)-5,(10+(border+2))/2+height-3,-4.5]){
            cube([10,3,6]);
        }
    }
