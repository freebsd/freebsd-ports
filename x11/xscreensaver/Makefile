# New ports collection makefile for:    xscreensaver
# Date created:         10 July 1995
# Whom:                 dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	xscreensaver
PORTVERSION=	3.32
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	DougB@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_MESA=	yes
WANT_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pam --with-gl --with-xpm --without-gnome \
		--with-zippy=/usr/games/fortune

MAN1=		attraction.1 blitspin.1 bouboule.1 braid.1 \
		bsod.1 bubbles.1 critical.1 decayscreen.1 \
		deco.1 distort.1 drift.1 epicycle.1 flag.1 flame.1 \
		forest.1 galaxy.1 gflux.1 gltext.1 goop.1 grav.1 greynetic.1 \
		halo.1 helix.1 hopalong.1 hyperball.1 hypercube.1 ifs.1 \
		imsmap.1 jigsaw.1 julia.1 kaleidescope.1 lament.1 laser.1 \
		lightning.1 lisa.1 lmorph.1 maze.1 moire.1 munch.1 nerverot.1 \
		noseguy.1 pedal.1 penrose.1 petri.1 phosphor.1 pyro.1 qix.1 \
		rd-bomb.1 rocks.1 rorschach.1 sierpinski.1 slidescreen.1 \
		slip.1 sonar.1 sphere.1 spiral.1 spotlight.1 squiral.1 \
		starfish.1 starwars.1 strange.1 swirl.1 t3d.1 vidwhacker.1 \
		vines.1 webcollage.1 whirlwindwarp.1 xflame.1 xjack.1 xlyap.1 \
		xmatrix.1 xscreensaver-command.1 xscreensaver-demo.1 \
		xscreensaver-gl-helper.1 xscreensaver.1 xsublim.1 xteevee.1 \
		zoom.1 molecule.1 rotzoomer.1 bumps.1 xscreensaver-getimage.1 \
		xscreensaver-getimage-file.1 xscreensaver-getimage-video.1

post-patch:
	@ ${CP} ${WRKSRC}/configure ${WRKSRC}/configure.Patched
	@ ${SED} -e 's#-lpthread#${PTHREAD_LIBS}#g' \
		${WRKSRC}/configure.Patched > ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
CONFIGURE_ARGS+=	--with-gtk
.endif

.include <bsd.port.post.mk>
