# New ports collection makefile for:   scrotwm
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	scrotwm
PORTVERSION=	0.9.33
CATEGORIES=	x11-wm
MASTER_SITES=	http://opensource.conformal.com/snapshots/scrotwm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aragon@phat.za.net
COMMENT=	A small, dynamic tiling window manager for X11

OPTIONS=	DMENU "Depend on x11/dmenu" Off \
		DMENU_BOTTOM "dmenu at screen bottom (instead of top)" Off

.include <bsd.port.pre.mk>

USE_XORG=	x11 xproto xrandr xt

MAN1=		scrotwm.1
USE_LDCONFIG=yes

.if defined(WITH_DMENU)
RUN_DEPENDS+=	dmenu:${PORTSDIR}/x11/dmenu
.endif
.if defined(WITH_DMENU_BOTTOM)
EXTRA_PATCHES+=	${FILESDIR}/spawn_menu_atbottom.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/scrotwm.*

do-build:
	${CC} ${CFLAGS} -I${X11BASE}/include \
		-I${WRKSRC}/linux -lutil -L${X11BASE}/lib -lX11 -lXrandr \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${X11BASE}/include -shared -fPIC \
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
	${INSTALL_SCRIPT} ${WRKSRC}/screenshot.sh ${EXAMPLESDIR}/

.include <bsd.port.post.mk>
