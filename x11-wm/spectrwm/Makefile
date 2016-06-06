# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	spectrwm
DISTVERSIONPREFIX=	SPECTRWM_
DISTVERSION=	3_0_2
CATEGORIES=	x11-wm

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Small, dynamic tiling window manager for X11

LICENSE=	ISCL

LIB_DEPENDS+=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS+=	dmenu:x11/dmenu

USE_GITHUB=	yes
GH_ACCOUNT=	conformal

USE_XORG=	x11 xcb xcursor xft xrandr xt

USE_LDCONFIG=	yes
PORTEXAMPLES=	spectrwm_cz.conf \
		spectrwm_es.conf \
		spectrwm_fr.conf \
		spectrwm_fr_ch.conf \
		spectrwm_se.conf \
		spectrwm_us.conf

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/spectrwm.*

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2 -I${WRKSRC}/freebsd \
		-lutil -L${LOCALBASE}/lib -lX11 -lX11-xcb -lxcb -lxcb-icccm \
		-lxcb-keysyms -lxcb-randr -lxcb-util -lxcb-xtest -lXcursor \
		-lXft -DSWM_LIB=\"${PREFIX}/lib/libswmhack.so\" \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include -shared -fpic -DPIC \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/screenshot.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libswmhack.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/spectrwm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/spectrwm.conf ${STAGEDIR}${PREFIX}/etc/spectrwm.conf.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for conf in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${conf} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
