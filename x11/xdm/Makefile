# $FreeBSD$

PORTNAME=	xdm
PORTVERSION=	1.1.11
PORTREVISION=	7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X display manager

LICENSE=	MIT

XORG_CAT=	app
USE_XORG=	xmu x11 xau xinerama xpm xdmcp xt xext xaw
CONFIGURE_ARGS+=	--with-xdmconfigdir=${PREFIX}/lib/X11/xdm \
			--with-xdmscriptdir=${PREFIX}/lib/X11/xdm \
			--with-authdir=/var/db/xdm

USES=		cpe libtool
CPE_PRODUCT=	x_display_manager
CPE_VENDOR=	x

CFFILES=	GiveConsole TakeConsole Xaccess Xreset Xresources \
		Xservers Xsession Xsetup_0 Xstartup Xwilling xdm-config

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	XDMSHELL XFT
OPTIONS_DEFAULT=	XFT
XDMSHELL_DESC=	Install xdmshell

XDMSHELL_CONFIGURE_ENABLE=	xdmshell

XFT_USE=	xorg=xft
XFT_CONFIGURE_WITH=	xft

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|XDMCONFIGDIR/|${PREFIX}/lib/X11/xdm/|" \
		-e "s|XDMSCRIPTDIR/|${PREFIX}/lib/X11/xdm/|" \
			${WRKSRC}/config/xdm-config.cpp \
			${WRKSRC}/config/Xstartup.cpp \
			${WRKSRC}/config/Xreset.cpp
	@${REINPLACE_CMD} -e "s|@DESTDIR@||" ${WRKSRC}/Makefile.in

post-install:
.for f in ${CFFILES}
	@${MV} ${STAGEDIR}${PREFIX}/lib/X11/xdm/${f} ${STAGEDIR}${PREFIX}/lib/X11/xdm/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}/var/db/xdm

.include <bsd.port.mk>
