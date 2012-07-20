# New ports collection makefile for:   scrotwm
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	spectrwm
PORTVERSION=	1.1.2
CATEGORIES=	x11-wm
MASTER_SITES=	https://opensource.conformal.com/snapshots/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	A small, dynamic tiling window manager for X11

LICENSE=	ISCL

OPTIONS_DEFINE=	DMENU_BOTTOM
DMENU_BOTTOM_DESC=	dmenu at screen bottom (instead of top)

.include <bsd.port.options.mk>

USE_XORG=	x11 xproto xrandr xt xtst

MAN1=		spectrwm.1
USE_LDCONFIG=	yes
PORTEXAMPLES=	spectrwm_cz.conf \
		spectrwm_es.conf \
		spectrwm_fr.conf \
		spectrwm_fr_ch.conf \
		spectrwm_se.conf \
		spectrwm_us.conf

RUN_DEPENDS+=	dmenu:${PORTSDIR}/x11/dmenu

.if ${PORT_OPTIONS:MDMENU_BOTTOM}
EXTRA_PATCHES+=	${FILESDIR}/spawn_menu_atbottom.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/spectrwm.*

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include \
		-I${WRKSRC}/freebsd -lutil -L${LOCALBASE}/lib -lX11 -lXrandr \
		-lXtst -DSWM_LIB=\"${PREFIX}/lib/libswmhack.so\" \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include -shared -fpic -DPIC \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/screenshot.sh ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libswmhack.so ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/spectrwm.1 ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/spectrwm.conf ${PREFIX}/etc/spectrwm.conf.sample
	@if [ ! -f ${PREFIX}/etc/spectrwm.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/spectrwm.conf.sample ${PREFIX}/etc/spectrwm.conf ; \
	fi
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for conf in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${conf} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
