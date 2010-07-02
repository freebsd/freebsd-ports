# New ports collection makefile for:   scrotwm
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	scrotwm
PORTVERSION=	0.9.24
CATEGORIES=	x11-wm
MASTER_SITES=	http://scrotwm.org/snapshot/ \
		http://www.peereboom.us/scrotwm/snapshot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aragon@phat.za.net
COMMENT=	A small, dynamic tiling window manager for X11

OPTIONS=	DMENU "Depend on x11/dmenu" Off \
		DMENU_BOTTOM "dmenu at screen bottom (instead of top)" Off

.include <bsd.port.pre.mk>

USE_XORG=	x11 xproto xrandr
USE_XLIB=	yes

MAN1=		scrotwm.1
PLIST_FILES=	bin/scrotwm bin/startscrotwm lib/libswmhack.so etc/scrotwm.conf
USE_LDCONFIG=yes

.if defined(WITH_DMENU)
RUN_DEPENDS+=	dmenu:${PORTSDIR}/x11/dmenu
.endif
.if defined(WITH_DMENU_BOTTOM)
EXTRA_PATCHES+=	${FILESDIR}/spawn_menu_atbottom.patch
.endif

do-build:
	${CC} ${CFLAGS} -I${X11BASE}/include \
		-I${WRKSRC}/linux -lutil -L${X11BASE}/lib -lX11 -lXrandr \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${X11BASE}/include -shared -fPIC \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/startscrotwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libswmhack.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/scrotwm.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/scrotwm.1 ${PREFIX}/man/man1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/scrotwm.*

.include <bsd.port.post.mk>
