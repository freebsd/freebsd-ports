# New ports collection makefile for:    xscreensaver
# Date created:         10 July 1995
# Whom:                 dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	xscreensaver
PORTVERSION=	5.08
PORTREVISION=	1
CATEGORIES?=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/ \
		http://dougbarton.us/Downloads/

MAINTAINER?=	DougB@FreeBSD.org
COMMENT=	Save your screen while you entertain your cat

LIB_DEPENDS=	gle.4:${PORTSDIR}/graphics/gle \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		glade-2.0.0:${PORTSDIR}/devel/libglade2

MAKE_JOBS_SAFE=	yes

USE_XORG=	xpm
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk --with-gl --with-gle --with-pixbuf --with-xpm \
		--with-jpeg=${LOCALBASE} --with-xshm-ext --with-xdbe-ext \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks/ \
		--with-configdir=${PREFIX}/share/xscreensaver/config/ \
		--with-dpms-ext --with-xinerama-ext --with-xf86vmode-ext \
		--with-xf86gamma-ext --with-randr-ext --enable-locking

OPTIONS=	ALL_FORTUNES "Run fortune with -sa argument" off \
		KERBEROS "Add support for kerberos" off \
		PAM "Add support for pam authentication" off \
		SETUID_HACKS "Install sonar hack suid so it can ping" off \
		SHEEP "Add extra port x11/electricsheep" off \
		FIREF "Add extra port x11/fireflies" off \
		XAOS1 "Add extra port graphics/xaos" off \
		XDALI "Add extra port x11-clocks/xdaliclock" off \
		XURTH "Add extra port astro/xearth" off \
		XMOUN "Add extra port graphics/xmountains" off \
		XPLAN "Add extra port astro/xplanet" off \
		XSNOW "Add extra port x11/xsnow" off

.include <bsd.port.pre.mk>

.if defined(WITH_ALL_FORTUNES)
CONFIGURE_ARGS+=	--with-fortune="/usr/games/fortune -sa"
.endif
.if defined(WITH_KERBEROS)
CONFIGURE_ARGS+=	--with-kerberos
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif
.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		PAM="@comment not installed: "
.endif
.if defined(WITH_SETUID_HACKS)
CONFIGURE_ARGS+=	--with-setuid-hacks
.endif

.if defined(WITH_SHEEP)
RUN_DEPENDS+=	electricsheep:${PORTSDIR}/x11/electricsheep
.endif
.if defined(WITH_FIREF)
RUN_DEPENDS+=	${X11BASE}/bin/xscreensaver-hacks/fireflies:${PORTSDIR}/x11/fireflies
.endif
.if defined(WITH_XAOS1)
RUN_DEPENDS+=	xaos:${PORTSDIR}/graphics/xaos
.endif
.if defined(WITH_XDALI)
RUN_DEPENDS+=	xdaliclock:${PORTSDIR}/x11-clocks/xdaliclock
.endif
.if defined(WITH_XURTH)
RUN_DEPENDS+=	xearth:${PORTSDIR}/astro/xearth
.endif
.if defined(WITH_XMOUN)
RUN_DEPENDS+=	xmountains:${PORTSDIR}/graphics/xmountains
.endif
.if defined(WITH_XPLAN)
RUN_DEPENDS+=	xplanet:${PORTSDIR}/astro/xplanet
.endif
.if defined(WITH_XSNOW)
RUN_DEPENDS+=	xsnow:${PORTSDIR}/x11/xsnow
.endif

.undef HAVE_GNOME

CONFIGURE_ENV=	X_CFLAGS=-I${LOCALBASE}/include/gnome-xml

MAN1=	xscreensaver-command.1 xscreensaver-demo.1 \
	xscreensaver-getimage-file.1 xscreensaver-getimage-video.1 \
	xscreensaver-getimage.1 xscreensaver-text.1 xscreensaver.1

MAN6=	anemone.6 anemotaxis.6 antinspect.6 antmaze.6 antspotlight.6 \
	apollonian.6 apple2.6 atlantis.6 attraction.6 atunnel.6 barcode.6 \
	blaster.6 blinkbox.6 blitspin.6 blocktube.6 boing.6 bouboule.6 \
	bouncingcow.6 boxed.6 boxfit.6 braid.6 bsod.6 bubble3d.6 \
	bumps.6 cage.6 carousel.6 ccurve.6 celtic.6 circuit.6 cloudlife.6 \
	compass.6 coral.6 crackberg.6 crystal.6 cube21.6 \
	cubenetic.6 cubestorm.6 cynosure.6 dangerball.6 decayscreen.6 deco.6 \
	deluxe.6 demon.6 discrete.6 distort.6 drift.6 endgame.6 engine.6 \
	epicycle.6 eruption.6 euler2d.6 extrusion.6 fadeplot.6 fiberlamp.6 \
	fireworkx.6 flame.6 flipflop.6 flipscreen3d.6 fliptext.6 flow.6 \
	fluidballs.6 flurry.6 flyingtoasters.6 fontglide.6 \
	fuzzyflakes.6 galaxy.6 gears.6 gflux.6 glblur.6 gleidescope.6 \
	glhanoi.6 glknots.6 glmatrix.6 glplanet.6 glschool.6 \
	glslideshow.6 glsnake.6 gltext.6 goop.6 grav.6 greynetic.6 halftone.6 \
	halo.6 helix.6 hopalong.6 hyperball.6 hypercube.6 hypertorus.6 ifs.6 \
	imsmap.6 interaggregate.6 interference.6 intermomentary.6 jigglypuff.6 \
	jigsaw.6 juggle.6 juggler3d.6 julia.6 kaleidescope.6 klein.6 kumppa.6 \
	lament.6 lavalite.6 ljlatest.6 \
	loop.6 maze.6 memscroller.6 menger.6 metaballs.6 mirrorblob.6 \
	moebius.6 moire.6 moire2.6 molecule.6 morph3d.6 mountain.6 \
	munch.6 nerverot.6 noof.6 noseguy.6 pacman.6 pedal.6 penetrate.6 \
	penrose.6 petri.6 phosphor.6 piecewise.6 pinion.6 pipes.6 polyhedra.6 \
	polyominoes.6 polytopes.6 pong.6 providence.6 pulsar.6 pyro.6 qix.6 \
	queens.6 rd-bomb.6 ripples.6 rocks.6 rorschach.6 rotzoomer.6 \
	rubik.6 sballs.6 shadebobs.6 sierpinski.6 sierpinski3d.6 slidescreen.6 \
	slip.6 sonar.6 speedmine.6 spheremonics.6 \
	spotlight.6 sproingies.6 squiral.6 stairs.6 starfish.6 \
	starwars.6 stonerview.6 strange.6 substrate.6 superquadrics.6 \
	swirl.6 tangram.6 thornbird.6 timetunnel.6 topblock.6 \
	triangle.6 truchet.6 twang.6 vermiculate.6 vidwhacker.6 \
	wander.6 webcollage.6 whirlwindwarp.6 wormhole.6 \
	xanalogtv.6 xflame.6 xjack.6 xlyap.6 xmatrix.6 xrayswarm.6 \
	xspirograph.6 zoom.6 cwaves.6 glcells.6 voronoi.6 \
	abstractile.6 moebiusgears.6 lockward.6 cubicgrid.6 hypnowheel.6 \
	lcdscrub.6 skytentacles.6 photopile.6 \
	xscreensaver-gl-helper.6

.if ${ARCH} == "amd64"
CFLAGS+=	-O0
.endif

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
		-e 's#/usr/X11R6#${LOCALBASE}#g' \
		${WRKSRC}/configure.Patched > ${WRKSRC}/configure
.if defined(WITH_PAM)
.for f in driver/passwd-pam.c driver/xscreensaver.man
	@ ${CP} ${WRKSRC}/${f} ${WRKSRC}/${f}.presed
	@ ${SED} -e "s#/etc/pam.d#${PREFIX}/etc/pam.d#g" \
	    ${WRKSRC}/${f}.presed > ${WRKSRC}/${f}
.endfor
	@ ${CP} ${FILESDIR}/xscreensaver.pam ${WRKSRC}/driver/xscreensaver.pam
.else
	@ ${CP} ${WRKSRC}/driver/Makefile.in ${WRKSRC}/driver/Makefile.in.post
	@ ${SED} -e "s#install-xml install-pam#install-xml#" \
	    ${WRKSRC}/driver/Makefile.in.post > ${WRKSRC}/driver/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/*.xml ${DATADIR}/config/
	@(if test -x ${LOCALBASE}/bin/xscreensaver-hacks/webcollage-helper; then \
		${ECHO} "bin/xscreensaver-hacks/webcollage-helper" | \
			${CAT} - ${TMPPLIST} > ${TMPPLIST}.cat && \
			${MV} ${TMPPLIST}.cat ${TMPPLIST}; fi)

.include <bsd.port.post.mk>
