--- esvrconf/ehacklist.h.orig	Sat Feb 28 04:52:22 2004
+++ esvrconf/ehacklist.h	Sat Feb 28 04:16:07 2004
@@ -18,195 +18,194 @@
 
 // This is from xscreensaver 4.0 XScreenSaver.ad
 
-char hacks[] = "								      \
-	   \"Qix (solid)\" 	qix -root -solid -segments 100		    \n\
-	   \"Qix (transparent)\" 	qix -root -count 4 -solid -transparent	    \n\
-		\"Qix (linear)\" 	qix -root -count 5 -solid -transparent	      \
-				  -linear -segments 250 -size 100	    \n\
-- mono: 	   \"Qix (xor)\" 	qix -root -linear -count 5 -size 200	      \
-				  -spread 30 -segments 75 -solid -xor	    \n\
-									      \
-	  \"Attraction (balls)\" 	attraction -root -mode balls		    \n\
-	  \"Attraction (lines)\" 	attraction -root -mode lines -points 3	      
-				  -segments 200				    \n\
--	   \"Attraction (poly)\" 	attraction -root -mode polygons		    \n\
-	\"Attraction (splines)\" 	attraction -root -mode splines -segments      \
-				  300					    \n\
-	\"Attraction (orbital)\" 	attraction -root -mode lines -radius 300      \
-				  -orbit -vmult 0.5			    \n\
-									      \
-				pyro -root				    \n\
-				rocks -root				    \n\
-				helix -root				    \n\
-				pedal -root				    \n\
-				rorschach -root -offset 7		    \n\
-				hopalong -root				    \n\
-				greynetic -root				    \n\
-				imsmap -root				    \n\
-				slidescreen -root			    \n\
-				decayscreen -root			    \n\
-				jigsaw -root				    \n\
-				blitspin -root -grab			    \n\
-				slip -root				    \n\
-				distort -root				    \n\
-				spotlight -root				    \n\
-	      \"Ripples (oily)\"	ripples -root -oily -light 2		    \n\
-	      \"Ripples (stir)\"	ripples -root -oily -light 2 -stir	    \n\
-	   \"Ripples (desktop)\"	ripples -root -water -light 6		    \n\
-				hypercube -root				    \n\
-				hyperball -root				    \n\
-				halo -root				    \n\
-				maze -root				    \n\
-				noseguy -root				    \n\
-				flame -root				    \n\
-				lmorph -root				    \n\
-				deco -root				    \n\
-				moire -root				    \n\
-				moire2 -root				    \n\
-				lightning -root				    \n\
-				strange -root				    \n\
-				spiral -root				    \n\
-				laser -root				    \n\
-				grav -root				    \n\
-	       \"Grav (trails)\" 	grav -root -trail -decay		    \n\
-				drift -root				    \n\
-				ifs -root				    \n\
-				julia -root				    \n\
-				penrose -root				    \n\
-				sierpinski -root			    \n\
-				braid -root				    \n\
-				galaxy -root				    \n\
-				bouboule -root				    \n\
-				swirl -root				    \n\
-				flag -root				    \n\
-				sphere -root				    \n\
-				forest -root				    \n\
-				lisa -root				    \n\
-				lissie -root				    \n\
-				goop -root -max-velocity 0.5 -elasticity      \
-				  0.9					    \n\
-				starfish -root				    \n\
-	     \"Starfish (blob)\" 	starfish -root -blob			    \n\
-				munch -root				    \n\
-				fadeplot -root				    \n\
-				coral -root -delay 0			    \n\
-				mountain -root				    \n\
-				triangle -root -delay 1			    \n\
-				worm -root				    \n\
-				rotor -root				    \n\
-				ant -root				    \n\
-				demon -root				    \n\
-				loop -root				    \n\
-				vines -root				    \n\
-				kaleidescope -root			    \n\
-				xjack -root				    \n\
-				xlyap -root -randomize			    \n\
-				cynosure -root				    \n\
-				flow -root				    \n\
-				epicycle -root				    \n\
-				interference -root			    \n\
-				truchet -root -randomize		    \n\
-				bsod -root				    \n\
-				crystal -root				    \n\
-				discrete -root				    \n\
-				kumppa -root				    \n\
-				rd-bomb -root				    \n\
-	    \"RD-Bomb (mobile)\" 	rd-bomb -root -speed 1 -size 0.1	    \n\
-				sonar -root				    \n\
-				t3d -root				    \n\
-				penetrate -root				    \n\
-				deluxe -root				    \n\
-				compass -root				    \n\
-				squiral -root				    \n\
-				xflame -root				    \n\
-				wander -root				    \n\
-	      \"Wander (spots)\" 	wander -root -advance 0 -size 10 -circles     \
-				  -length 10000 -reset 100000		    \n\
-				critical -root				    \n\
-				phosphor -root				    \n\
-				xmatrix -root				    \n\
-				petri -root -size 2 -count 20		    \n\
-		     \"Petri 2\" 	petri -root -minlifespeed 0.02		      \
-				  -maxlifespeed 0.03 -minlifespan 1	      \
-				  -maxlifespan 1 -instantdeathchan 0	      \
-				  -minorchan 0 -anychan 0.3		    \n\
-				shadebobs -root				    \n\
-				ccurve -root				    \n\
-				blaster -root				    \n\
-				bumps -root				    \n\
-				xteevee -root				    \n\
-				xspirograph -root			    \n\
-				nerverot -root				    \n\
--	    \"NerveRot (dense)\"	nerverot -root -count 1000		    \n\
--	    \"NerveRot (thick)\"	nerverot -root -count 100 -line-width 4       \
-			        -max-nerve-radius 0.8 -nervousness 0.5 -db  \n\
-				xrayswarm -root				    \n\
--	       \"Zoom (Fatbits)\"	zoom -root				    \n\
-	       \"Zoom (Lenses)\"	zoom -root -lenses			    \n\
-				rotzoomer -root				    \n\
--	   \"RotZoomer (mobile)\" rotzoomer -root -move			    \n\
--	   \"RotZoomer (sweep)\"  rotzoomer -root -sweep			    \n\
-				whirlwindwarp -root			    \n\
- 	            \"WhirlyGig\"	whirlygig -root				    \n\
- 	            \"SpeedMine\"	speedmine -root				    \n\
- 	            \"SpeedWorm\"	speedmine -root -worm			    \n\
- 	                	vermiculate -root			    \n\
-  color: 			bubbles -root				    \n\
-  default-n:			webcollage -root			    \n\
-  default-n:  \"WebCollage (whacked)\"					      \
-				webcollage -root -filter		      \
-				  'vidwhacker -stdin -stdout'		    \n\
-- default-n:			vidwhacker -root			    \n\
-									      \
-	   GL:			gears -root				    \n\
-	   GL:	\"Gears (planetary)\" gears -root -planetary		    \n\
-	   GL:			superquadrics -root			    \n\
-	   GL:			morph3d -root				    \n\
-	   GL:			cage -root				    \n\
-	   GL:			moebius -root				    \n\
-	   GL:			stairs -root				    \n\
-	   GL:			pipes -root				    \n\
-	   GL:			sproingies -root			    \n\
-	   GL:			rubik -root				    \n\
-	   GL:			atlantis -root				    \n\
-	   GL:			lament -root				    \n\
-	   GL:			bubble3d -root				    \n\
-	   GL:			glplanet -root				    \n\
-	   GL:			pulsar -root				    \n\
--	   GL:	   \"Pulsar (textures)\"					      \
-				  pulsar -root -texture -mipmap		      \
-				  -texture_quality -light -fog		    \n\
--	   GL:			extrusion -root				    \n\
-	   GL:			sierpinski3d -root			    \n\
-	   GL:			menger -root				    \n\
-	   GL:	 \"GFlux\"	gflux -root				    \n\
-	   GL:	 \"GFlux (grab)\"	gflux -root -mode grab			    \n\
-	   GL:			stonerview -root			    \n\
-	   GL:			starwars -root				    \n\
-	   GL:			gltext -root				    \n\
-	   GL:	\"GLText (clock)\" gltext -text \"%A%n%d %b %Y%n%r\" -root	    \n\
-	   GL:	 \"Molecule\"		molecule -root			    \n\
-	   GL:	 \"Molecule (lumpy)\"	molecule -root -no-bonds -no-labels \n\
-	   GL:			dangerball -root			    \n\
-	   GL:			circuit -root				    \n\
-	   GL:			engine -root				    \n\
-	   GL:			flipscreen3d -root			    \n\
-									      \
--				xdaliclock -root -builtin3 -cycle	    \n\
-- default-n:			xearth -nofork -nostars -ncolors 50	      \
-				  -night 3 -wait 0 -timewarp 400.0 -pos	      \
-				  sunrel/38/-30				    \n\
--				xplanetbg -xscreensaver -moonside             \
-                                  -markerfile earth -wait 1 -timewarp 400   \n\
--				ssystem -fullscreen :32			    \n\
--				xmountains -b -M -Z 0 -r 1		    \n\
--	\"XMountains (top)\"	xmountains -b -M -Z 0 -r 1 -m		    \n\
--                               xaos -fullscreen -autopilot                   \
-                                  -incoloring -1 -outcoloring -1            \n\
--				xfishtank -d -s                             \n\
--				xsnow                                       \n\
--				goban -root                                 \n\
--				electricsheep                               \n\
--				cosmos -root                                \n\
--	   GL:                  sphereEversion --root                       \n";
-
+char hacks[] = "								      "\
+"	   \"Qix (solid)\" 	qix -root -solid -segments 100		    \n"\
+"	   \"Qix (transparent)\" 	qix -root -count 4 -solid -transparent	    \n"\
+"		\"Qix (linear)\" 	qix -root -count 5 -solid -transparent	      "\
+"				  -linear -segments 250 -size 100	    \n"\
+"- mono: 	   \"Qix (xor)\" 	qix -root -linear -count 5 -size 200	      "\
+"				  -spread 30 -segments 75 -solid -xor	    \n"\
+"									      "\
+"	  \"Attraction (balls)\" 	attraction -root -mode balls		    \n"\
+"	  \"Attraction (lines)\" 	attraction -root -mode lines -points 3	     "\
+"				  -segments 200				    \n"\
+"-	   \"Attraction (poly)\" 	attraction -root -mode polygons		    \n"\
+"	\"Attraction (splines)\" 	attraction -root -mode splines -segments      "\
+"				  300					    \n"\
+"	\"Attraction (orbital)\" 	attraction -root -mode lines -radius 300      "\
+"				  -orbit -vmult 0.5			    \n"\
+"									      "\
+"				pyro -root				    \n"\
+"				rocks -root				    \n"\
+"				helix -root				    \n"\
+"				pedal -root				    \n"\
+"				rorschach -root -offset 7		    \n"\
+"				hopalong -root				    \n"\
+"				greynetic -root				    \n"\
+"				imsmap -root				    \n"\
+"				slidescreen -root			    \n"\
+"				decayscreen -root			    \n"\
+"				jigsaw -root				    \n"\
+"				blitspin -root -grab			    \n"\
+"				slip -root				    \n"\
+"				distort -root				    \n"\
+"				spotlight -root				    \n"\
+"	      \"Ripples (oily)\"	ripples -root -oily -light 2		    \n"\
+"	      \"Ripples (stir)\"	ripples -root -oily -light 2 -stir	    \n"\
+"	   \"Ripples (desktop)\"	ripples -root -water -light 6		    \n"\
+"				hypercube -root				    \n"\
+"				hyperball -root				    \n"\
+"				halo -root				    \n"\
+"				maze -root				    \n"\
+"				noseguy -root				    \n"\
+"				flame -root				    \n"\
+"				lmorph -root				    \n"\
+"				deco -root				    \n"\
+"				moire -root				    \n"\
+"				moire2 -root				    \n"\
+"				lightning -root				    \n"\
+"				strange -root				    \n"\
+"				spiral -root				    \n"\
+"				laser -root				    \n"\
+"				grav -root				    \n"\
+"	       \"Grav (trails)\" 	grav -root -trail -decay		    \n"\
+"				drift -root				    \n"\
+"				ifs -root				    \n"\
+"				julia -root				    \n"\
+"				penrose -root				    \n"\
+"				sierpinski -root			    \n"\
+"				braid -root				    \n"\
+"				galaxy -root				    \n"\
+"				bouboule -root				    \n"\
+"				swirl -root				    \n"\
+"				flag -root				    \n"\
+"				sphere -root				    \n"\
+"				forest -root				    \n"\
+"				lisa -root				    \n"\
+"				lissie -root				    \n"\
+"				goop -root -max-velocity 0.5 -elasticity      "\
+"				  0.9					    \n"\
+"				starfish -root				    \n"\
+"	     \"Starfish (blob)\" 	starfish -root -blob			    \n"\
+"				munch -root				    \n"\
+"				fadeplot -root				    \n"\
+"				coral -root -delay 0			    \n"\
+"				mountain -root				    \n"\
+"				triangle -root -delay 1			    \n"\
+"				worm -root				    \n"\
+"				rotor -root				    \n"\
+"				ant -root				    \n"\
+"				demon -root				    \n"\
+"				loop -root				    \n"\
+"				vines -root				    \n"\
+"				kaleidescope -root			    \n"\
+"				xjack -root				    \n"\
+"				xlyap -root -randomize			    \n"\
+"				cynosure -root				    \n"\
+"				flow -root				    \n"\
+"				epicycle -root				    \n"\
+"				interference -root			    \n"\
+"				truchet -root -randomize		    \n"\
+"				bsod -root				    \n"\
+"				crystal -root				    \n"\
+"				discrete -root				    \n"\
+"				kumppa -root				    \n"\
+"				rd-bomb -root				    \n"\
+"	    \"RD-Bomb (mobile)\" 	rd-bomb -root -speed 1 -size 0.1	    \n"\
+"				sonar -root				    \n"\
+"				t3d -root				    \n"\
+"				penetrate -root				    \n"\
+"				deluxe -root				    \n"\
+"				compass -root				    \n"\
+"				squiral -root				    \n"\
+"				xflame -root				    \n"\
+"				wander -root				    \n"\
+"	      \"Wander (spots)\" 	wander -root -advance 0 -size 10 -circles     "\
+"				  -length 10000 -reset 100000		    \n"\
+"				critical -root				    \n"\
+"				phosphor -root				    \n"\
+"				xmatrix -root				    \n"\
+"				petri -root -size 2 -count 20		    \n"\
+"		     \"Petri 2\" 	petri -root -minlifespeed 0.02		      "\
+"				  -maxlifespeed 0.03 -minlifespan 1	      "\
+"				  -maxlifespan 1 -instantdeathchan 0	      "\
+"				  -minorchan 0 -anychan 0.3		    \n"\
+"				shadebobs -root				    \n"\
+"				ccurve -root				    \n"\
+"				blaster -root				    \n"\
+"				bumps -root				    \n"\
+"				xteevee -root				    \n"\
+"				xspirograph -root			    \n"\
+"				nerverot -root				    \n"\
+"-	    \"NerveRot (dense)\"	nerverot -root -count 1000		    \n"\
+"-	    \"NerveRot (thick)\"	nerverot -root -count 100 -line-width 4       "\
+"			        -max-nerve-radius 0.8 -nervousness 0.5 -db  \n"\
+"				xrayswarm -root				    \n"\
+"-	       \"Zoom (Fatbits)\"	zoom -root				    \n"\
+"	       \"Zoom (Lenses)\"	zoom -root -lenses			    \n"\
+"				rotzoomer -root				    \n"\
+"-	   \"RotZoomer (mobile)\" rotzoomer -root -move			    \n"\
+"-	   \"RotZoomer (sweep)\"  rotzoomer -root -sweep			    \n"\
+"				whirlwindwarp -root			    \n"\
+" 	            \"WhirlyGig\"	whirlygig -root				    \n"\
+" 	            \"SpeedMine\"	speedmine -root				    \n"\
+" 	            \"SpeedWorm\"	speedmine -root -worm			    \n"\
+" 	                	vermiculate -root			    \n"\
+"  color: 			bubbles -root				    \n"\
+"  default-n:			webcollage -root			    \n"\
+"  default-n:  \"WebCollage (whacked)\"					      "\
+"				webcollage -root -filter		      "\
+"				  'vidwhacker -stdin -stdout'		    \n"\
+"- default-n:			vidwhacker -root			    \n"\
+"									      "\
+"	   GL:			gears -root				    \n"\
+"	   GL:	\"Gears (planetary)\" gears -root -planetary		    \n"\
+"	   GL:			superquadrics -root			    \n"\
+"	   GL:			morph3d -root				    \n"\
+"	   GL:			cage -root				    \n"\
+"	   GL:			moebius -root				    \n"\
+"	   GL:			stairs -root				    \n"\
+"	   GL:			pipes -root				    \n"\
+"	   GL:			sproingies -root			    \n"\
+"	   GL:			rubik -root				    \n"\
+"	   GL:			atlantis -root				    \n"\
+"	   GL:			lament -root				    \n"\
+"	   GL:			bubble3d -root				    \n"\
+"	   GL:			glplanet -root				    \n"\
+"	   GL:			pulsar -root				    \n"\
+"-	   GL:	   \"Pulsar (textures)\"					      "\
+"				  pulsar -root -texture -mipmap		      "\
+"				  -texture_quality -light -fog		    \n"\
+"-	   GL:			extrusion -root				    \n"\
+"	   GL:			sierpinski3d -root			    \n"\
+"	   GL:			menger -root				    \n"\
+"	   GL:	 \"GFlux\"	gflux -root				    \n"\
+"	   GL:	 \"GFlux (grab)\"	gflux -root -mode grab			    \n"\
+"	   GL:			stonerview -root			    \n"\
+"	   GL:			starwars -root				    \n"\
+"	   GL:			gltext -root				    \n"\
+"	   GL:	\"GLText (clock)\" gltext -text \"%A%n%d %b %Y%n%r\" -root	    \n"\
+"	   GL:	 \"Molecule\"		molecule -root			    \n"\
+"	   GL:	 \"Molecule (lumpy)\"	molecule -root -no-bonds -no-labels \n"\
+"	   GL:			dangerball -root			    \n"\
+"	   GL:			circuit -root				    \n"\
+"	   GL:			engine -root				    \n"\
+"	   GL:			flipscreen3d -root			    \n"\
+"									      "\
+"-				xdaliclock -root -builtin3 -cycle	    \n"\
+"- default-n:			xearth -nofork -nostars -ncolors 50	      "\
+"				  -night 3 -wait 0 -timewarp 400.0 -pos	      "\
+"				  sunrel/38/-30				    \n"\
+"-				xplanetbg -xscreensaver -moonside             "\
+"                                  -markerfile earth -wait 1 -timewarp 400   \n"\
+"-				ssystem -fullscreen :32			    \n"\
+"-				xmountains -b -M -Z 0 -r 1		    \n"\
+"-	\"XMountains (top)\"	xmountains -b -M -Z 0 -r 1 -m		    \n"\
+"-                               xaos -fullscreen -autopilot                   "\
+"                                  -incoloring -1 -outcoloring -1            \n"\
+"-				xfishtank -d -s                             \n"\
+"-				xsnow                                       \n"\
+"-				goban -root                                 \n"\
+"-				electricsheep                               \n"\
+"-				cosmos -root                                \n"\
+"-	   GL:                  sphereEversion --root                       \n";
