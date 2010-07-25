# New ports collection makefile for:	xscreensaver-gnome
# Date created:				13th February 2002
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/xscreensaver-gnome/Makefile,v 1.5 2007/08/15 18:29:16 mezz Exp $
#

PORTNAME?=	xscreensaver-gnome
PORTVERSION=	5.11
PORTREVISION?=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.jwz.org/xscreensaver/
DISTNAME=	xscreensaver-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Save your screen while you entertain your cat (for GNOME users)

LIB_DEPENDS=	gle.4:${PORTSDIR}/graphics/gle \
		jpeg.11:${PORTSDIR}/graphics/jpeg

CONFLICTS?=	xscreensaver-[0-9]* xscreensaver-gnome-hacks-[0-9]*

USE_XORG=	x11 xpm
USE_GL=		gl
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_GNOME=	gnomehier libglade2 gnomehack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk --with-gl --with-gle --with-pixbuf --with-xpm \
		--with-jpeg=${LOCALBASE} --with-xshm-ext --with-xdbe-ext \
		--with-hackdir=${PREFIX}/bin/xscreensaver-hacks \
		--with-configdir=${PREFIX}/share/xscreensaver/config \
		--with-dpms-ext --with-xinerama-ext --with-xf86vmode-ext \
		--with-xf86gamma-ext --with-randr-ext --enable-locking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS?=	PAM "Pluggable Authentication Module support" on \
		KEYRING "Enable GnomeKeyring integration (needs PAM)" on \
		ALL_FORTUNES "Enable support for all fortunes" off \
		SETUID_HACKS "Install sonar hack suid so it can ping" off

SUB_FILES+=	xscreensaver.pam

MAN1?=	xscreensaver-command.1 xscreensaver-demo.1 \
	xscreensaver-getimage-file.1 xscreensaver-getimage-video.1 \
	xscreensaver-getimage.1 xscreensaver-text.1 xscreensaver.1

MAN6?=	anemone.6 anemotaxis.6 antinspect.6 antmaze.6 antspotlight.6 \
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
	halo.6 helix.6 hopalong.6 hypertorus.6 ifs.6 \
	imsmap.6 interaggregate.6 interference.6 intermomentary.6 jigglypuff.6 \
	jigsaw.6 juggler3d.6 julia.6 kaleidescope.6 klein.6 kumppa.6 \
	lament.6 lavalite.6 ljlatest.6 \
	loop.6 maze.6 memscroller.6 menger.6 metaballs.6 mirrorblob.6 \
	moebius.6 moire.6 moire2.6 molecule.6 morph3d.6 mountain.6 \
	munch.6 nerverot.6 noof.6 noseguy.6 pacman.6 pedal.6 penetrate.6 \
	penrose.6 petri.6 phosphor.6 photopile.6 piecewise.6 pinion.6 \
	pipes.6 polyhedra.6 polyominoes.6 polytopes.6 pong.6 providence.6 \
	pulsar.6 pyro.6 qix.6 queens.6 rd-bomb.6 ripples.6 rocks.6 \
	rorschach.6 rotzoomer.6 rubik.6 sballs.6 shadebobs.6 sierpinski.6 \
	sierpinski3d.6 slidescreen.6 slip.6 sonar.6 speedmine.6 spheremonics.6 \
	spotlight.6 sproingies.6 squiral.6 stairs.6 starfish.6 \
	starwars.6 stonerview.6 strange.6 substrate.6 superquadrics.6 \
	swirl.6 tangram.6 thornbird.6 timetunnel.6 topblock.6 \
	triangle.6 truchet.6 twang.6 vermiculate.6 vidwhacker.6 \
	wander.6 webcollage.6 whirlwindwarp.6 wormhole.6 \
	xanalogtv.6 xflame.6 xjack.6 xlyap.6 xmatrix.6 xrayswarm.6 \
	xspirograph.6 zoom.6 cwaves.6 glcells.6 voronoi.6 \
	abstractile.6 moebiusgears.6 lockward.6 cubicgrid.6 hypnowheel.6 \
	lcdscrub.6 skytentacles.6 rubikblocks.6 surfaces.6 \
	xscreensaver-gl-helper.6

.include <bsd.port.pre.mk>

.if defined(WITH_ALL_FORTUNES)
CONFIGURE_ARGS+=	--with-fortune="/usr/games/fortune -sa"
.endif

.if defined(WITH_PAM) || defined(WITH_KEYRING)
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		PAM="@comment "
.endif

.if defined(WITH_KEYRING)
SUB_LIST+=		PAM_KEYRING=
RUN_DEPENDS+=		${LOCALBASE}/lib/pam_gnome_keyring.so:${PORTSDIR}/security/gnome-keyring
.else
SUB_LIST+=		PAM_KEYRING=\#
.endif

.if defined(WITH_SETUID_HACKS)
CONFIGURE_ARGS+=	--with-setuid-hacks
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-O0
.endif

USE_DOS2UNIX=	hacks/glx/topblock.c
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
	    	s|malloc.h|stdlib.h|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure
.if defined(WITH_PAM)
.for f in driver/passwd-pam.c driver/xscreensaver.man
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
	    	${WRKSRC}/${f}
.endfor
.else
	@${REINPLACE_CMD} -e 's|install-xml install-pam|install-xml|' \
	    	${WRKSRC}/driver/Makefile.in
.endif

pre-build:
	@(cd ${WRKSRC}/hacks && ./m6502.sh m6502.h images/m6502/*.asm)
	@(cd ${WRKSRC}/hacks/glx && ./molecules.sh molecules.h ../images/molecules/*.pdb)

pre-install:
.if defined(WITH_PAM)
	@${CP} ${WRKDIR}/xscreensaver.pam ${WRKSRC}/driver/xscreensaver.pam
.endif

.if !target(post-install-slave)
post-install-slave:
	@${DO_NADA}
.endif

post-install: post-install-slave
	@(if test -x ${PREFIX}/bin/xscreensaver-hacks/webcollage-helper; then \
	    	${ECHO} "bin/xscreensaver-hacks/webcollage-helper" | \
			${CAT} - ${TMPPLIST} > ${TMPPLIST}.cat && \
			${MV} ${TMPPLIST}.cat ${TMPPLIST}; fi)

.include <bsd.port.post.mk>
