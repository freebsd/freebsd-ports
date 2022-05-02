# Created by: Aragon Gouveia <aragon@phat.za.net>

PORTNAME=	spectrwm
DISTVERSIONPREFIX=	SPECTRWM_
DISTVERSION=	3_4_1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, dynamic tiling window manager for X11

LICENSE=	ISCL

LIB_DEPENDS+=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS+=	dmenu:x11/dmenu

USE_GITHUB=	yes
GH_ACCOUNT=	conformal

OPTIONS_DEFINE=	EXAMPLES

.include	<bsd.port.options.mk>

USES=		compiler:c11 xorg
USE_XORG=	x11 xcb xcursor xft xrandr xt

USE_LDCONFIG=	yes
CONFEXAMPLES=	spectrwm_cz.conf \
		spectrwm_es.conf \
		spectrwm_fr.conf \
		spectrwm_fr_ch.conf \
		spectrwm_se.conf \
		spectrwm_us.conf

SCRIPTEXAMPLES=	baraction.sh \
		screenshot.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/spectrwm.*

do-build:
	ln -sf ${WRKSRC}/linux/pledge.h ${WRKSRC}/pledge.h
	${CC} ${CFLAGS} -Wall -Wextra -Wshadow -Werror -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2 -I${WRKSRC}/freebsd \
		-lutil -L${LOCALBASE}/lib -lX11 -lX11-xcb -lxcb -lxcb-icccm \
		-lxcb-keysyms -lxcb-randr -lxcb-util -lxcb-xinput -lxcb-xtest \
		-lXcursor -lXft -DSWM_LIB=\"${PREFIX}/lib/libswmhack.so\" \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -Wall -Wextra -Wshadow -Werror -I${LOCALBASE}/include \
		-shared -fpic -DPIC -L${LOCALBASE}/lib -lX11 \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libswmhack.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/spectrwm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/spectrwm.conf ${STAGEDIR}${PREFIX}/etc/spectrwm.conf.sample

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in ${CONFEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for file in ${SCRIPTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
