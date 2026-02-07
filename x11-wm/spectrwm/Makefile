PORTNAME=	spectrwm
DISTVERSIONPREFIX=	SPECTRWM_
DISTVERSION=	3_7_0
CATEGORIES=	x11-wm

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Small, dynamic tiling window manager for X11
WWW=		https://github.com/conformal/spectrwm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS+=	dmenu:x11/dmenu \
		xlock:x11/xlockmore \
		xterm:x11/xterm

USES=		compiler:c11 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	conformal
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb xcursor xft xrandr xt

MAKE_ARGS+=	-C \
		freebsd

CONFEXAMPLES=	spectrwm_cz.conf spectrwm_es.conf spectrwm_fr.conf \
		spectrwm_fr_ch.conf spectrwm_se.conf spectrwm_us.conf

SCRIPTEXAMPLES=	baraction.sh screenshot.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/spectrwm.c \
		${WRKSRC}/spectrwm.1

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/freebsd/libswmhack.so \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/spectrwm.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/spectrwm.conf \
		${STAGEDIR}${PREFIX}/etc/spectrwm.conf.sample
	${INSTALL_DATA} ${CONFEXAMPLES:C|^|${WRKSRC}/|} \
			${SCRIPTEXAMPLES:C|^|${WRKSRC}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
