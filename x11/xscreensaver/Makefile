# New ports collection makefile for:    xscreensaver
# Date created:         10 July 1995
# Whom:                 dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

#************************************************************************
#									*
#	DO NOT COMMIT TO THIS PORT WITHOUT MY PERMISSION. THANKS.	*
#									*
#************************************************************************

PORTNAME=	xscreensaver
PORTVERSION=	4.14
PORTREVISION=	1
CATEGORIES?=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER?=	DougB@FreeBSD.org
COMMENT=	Save your screen while you entertain your cat

LIB_DEPENDS=	gle.3:${PORTSDIR}/graphics/gle \
		xml.5:${PORTSDIR}/textproc/libxml

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pam --with-gl --with-gle --with-xpm --with-xml \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks/ \
		--with-configdir=${PREFIX}/share/xscreensaver/config/ \
		--with-jpeg=${LOCALBASE} --without-gnome --without-kerberos \
		--without-motif

.include <bsd.port.pre.mk>

.if defined(XS_WITH_ALL_FORTUNES)
CONFIGURE_ARGS+=	--with-fortune="/usr/games/fortune -sa"
.endif
.if defined(XS_WITH_SETUID_HACKS)
CONFIGURE_ARGS+=	--with-setuid-hacks
.endif

.undef HAVE_GNOME

CONFIGURE_ENV=	X_CFLAGS=-I${LOCALBASE}/include/gnome-xml

MAN1=	anemone.1 ant.1 apollonian.1 atlantis.1 attraction.1 blaster.1 \
	blitspin.1 bouboule.1 boxed.1 braid.1 bsod.1 bubble3d.1 bubbles.1 \
	bumps.1 cage.1 ccurve.1 circuit.1 compass.1 coral.1 critical.1 \
	crystal.1 cubenetic.1 cynosure.1 dangerball.1 decayscreen.1 deco.1 \
	deluxe.1 demon.1 discrete.1 distort.1 drift.1 engine.1 epicycle.1 \
	euler2d.1 extrusion.1 fadeplot.1 flag.1 flame.1 flipscreen3d.1 flow.1 \
	fluidballs.1 forest.1 galaxy.1 gears.1 gflux.1 glforestfire.1 \
	glplanet.1 glsnake.1 gltext.1 goop.1 grav.1 greynetic.1 halo.1 helix.1 \
	hopalong.1 hyperball.1 hypercube.1 ifs.1 imsmap.1 interference.1 \
	jigsaw.1 juggle.1 julia.1 kaleidescope.1 kumppa.1 lament.1 laser.1 \
	lavalite.1 lightning.1 lisa.1 lissie.1 lmorph.1 loop.1 maze.1 menger.1 \
	moebius.1 moire.1 moire2.1 molecule.1 morph3d.1 mountain.1 munch.1 \
	nerverot.1 noseguy.1 pedal.1 penetrate.1 penrose.1 petri.1 phosphor.1 \
	pipes.1 polyominoes.1 pulsar.1 pyro.1 qix.1 queens.1 rd-bomb.1 \
	ripples.1 rocks.1 rorschach.1 rotor.1 rotzoomer.1 rubik.1 sballs.1 \
	shadebobs.1 sierpinski.1 sierpinski3d.1 slidescreen.1 slip.1 sonar.1 \
	speedmine.1 sphere.1 spheremonics.1 spiral.1 spotlight.1 sproingies.1 \
	squiral.1 stairs.1 starfish.1 starwars.1 stonerview.1 strange.1 \
	superquadrics.1 swirl.1 t3d.1 thornbird.1 triangle.1 truchet.1 twang.1 \
	vermiculate.1 vidwhacker.1 vines.1 wander.1 webcollage.1 \
	whirlwindwarp.1 whirlygig.1 worm.1 xflame.1 xjack.1 xlyap.1 \
	xmatrix.1 xrayswarm.1 xspirograph.1 xsublim.1 xteevee.1 zoom.1 \
	endgame.1 glblur.1 halftone.1 barcode.1 eruption.1 flurry.1 metaballs.1 \
	atunnel.1 piecewise.1 bouncingcow.1 flyingtoasters.1 glslideshow.1 \
	jigglypuff.1 klein.1 cloudlife.1 hypertorus.1 glmatrix.1 cubestorm.1 \
	glknots.1 blocktube.1 flipflop.1 antspotlight.1 polytopes.1 ljlatest.1 \
	apple2.1 blinkbox.1 fontglide.1 gleidescope.1 mirrorblob.1 pong.1 \
	xanalogtv.1 \
	xscreensaver-command.1 xscreensaver-demo.1 \
	xscreensaver-getimage-file.1 xscreensaver-getimage-video.1 \
	xscreensaver-getimage.1 xscreensaver-gl-helper.1 xscreensaver.1

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO} ''
	@${ECHO} '*** This is the non-gnome version of the port.'
	@${ECHO} '    If you want gnome support, hit Ctrl-C now,'
	@${ECHO} '    and cd ../xscreensaver-gnome.'
	@${ECHO} ''
	@sleep 2
.endif

post-patch:
	@ ${CP} ${WRKSRC}/configure ${WRKSRC}/configure.Patched
	@ ${SED} -e 's#-lpthread#${PTHREAD_LIBS}#g' \
		-e 's#malloc.h#stdlib.h#g' \
		${WRKSRC}/configure.Patched > ${WRKSRC}/configure

post-install:
	@(if test -x ${X11BASE}/bin/xscreensaver-hacks/webcollage-helper; then \
		${ECHO} "bin/xscreensaver-hacks/webcollage-helper" | \
			${CAT} - ${TMPPLIST} > ${TMPPLIST}.cat && \
			${MV} ${TMPPLIST}.cat ${TMPPLIST}; fi)

.include <bsd.port.post.mk>
