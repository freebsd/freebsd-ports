# New ports collection makefile for:    xscreensaver
# Version required:     3.21
# Date created:         10 July 1995
# Whom:                 dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

DISTNAME=	xscreensaver-3.21
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		MesaGL.14:${PORTSDIR}/graphics/Mesa3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pam --with-gl --with-gle --with-xpm
USE_X_PREFIX=	yes
MAN1= 		attraction.1 blitspin.1 bouboule.1 braid.1 \
		bsod.1 bubbles.1 critical.1 decayscreen.1 \
		deco.1 distort.1 drift.1 epicycle.1 flag.1 flame.1 \
		forest.1 galaxy.1 goop.1 grav.1 greynetic.1 \
		halo.1 helix.1 hopalong.1 hypercube.1 ifs.1 \
		imsmap.1 jigsaw.1 julia.1 kaleidescope.1 lament.1 laser.1 \
		lightning.1 lisa.1 lmorph.1 maze.1 moire.1 munch.1 noseguy.1 \
		pedal.1 penrose.1 phosphor.1 pyro.1 qix.1 rd-bomb.1 rocks.1 \
		rorschach.1 sierpinski.1 slidescreen.1 slip.1 sonar.1 sphere.1\
		spiral.1 spotlight.1 squiral.1 starfish.1 strange.1 swirl.1 \
		t3d.1 vidwhacker.1 vines.1 webcollage.1 xjack.1 xlyap.1 \
		xmatrix.1 xroger.1 xscreensaver-command.1 xscreensaver-demo.1 \
		xscreensaver.1 xsublim.1

.include <bsd.port.mk>
