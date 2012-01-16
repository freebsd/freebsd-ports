# New ports collection makefile for:   scrotwm
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	scrotwm
PORTVERSION=	0.10.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://opensource.conformal.com/snapshots/scrotwm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zeising@daemonic.se
COMMENT=	A small, dynamic tiling window manager for X11

LICENSE=	ISCL

OPTIONS=	DMENU_BOTTOM "dmenu at screen bottom (instead of top)" Off

.include <bsd.port.pre.mk>

USE_XORG=	x11 xproto xrandr xt xtst

MAN1=		scrotwm.1
USE_LDCONFIG=yes

RUN_DEPENDS+=	dmenu:${PORTSDIR}/x11/dmenu

.if defined(WITH_DMENU_BOTTOM)
EXTRA_PATCHES+=	${FILESDIR}/spawn_menu_atbottom.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/scrotwm.*

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include \
		-I${WRKSRC}/freebsd -lutil -L${LOCALBASE}/lib -lX11 -lXrandr \
		-lXtst -DSWM_LIB=\"${PREFIX}/lib/libwmhack.so\" \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include -shared -fpic -DPIC \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libswmhack.so ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/scrotwm.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/scrotwm.conf ${PREFIX}/etc/scrotwm.conf.sample
	@if [ ! -f ${PREFIX}/etc/scrotwm.conf ]; then \
		${CP} -p ${PREFIX}/etc/scrotwm.conf.sample ${PREFIX}/etc/scrotwm.conf ; \
	fi
	${INSTALL_SCRIPT} ${FILESDIR}/startscrotwm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/screenshot.sh ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_cz.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_es.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_fr.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_fr_ch.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_se.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scrotwm_us.conf ${EXAMPLESDIR}

.include <bsd.port.post.mk>
