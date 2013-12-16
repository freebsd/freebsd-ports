# $FreeBSD$

PORTNAME=	xdm
PORTVERSION=	1.1.11
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X display manager

LICENSE=	MIT

XORG_CAT=	app
USE_XORG=	xmu x11 xau xinerama xpm xdmcp xt xext xaw
CONFIGURE_ARGS+=	--with-xdmconfigdir=${EXAMPLESDIR} \
			--with-xdmscriptdir=${EXAMPLESDIR}

CFFILES=	GiveConsole TakeConsole Xaccess Xreset Xresources \
		Xservers Xsession Xsetup_0 Xstartup Xwilling xdm-config

OPTIONS_DEFINE=	XDMSHELL
XDMSHELL_DESC=	Install xdmshell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXDMSHELL}
CONFIGURE_ARGS+=--enable-xdmshell
PLIST_SUB+=	XDMSHELL=""
.else
CONFIGURE_ARGS+=--disable-xdmshell
PLIST_SUB+=	XDMSHELL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|XDMCONFIGDIR/|${PREFIX}/lib/X11/xdm/|" \
		-e "s|XDMSCRIPTDIR/|${PREFIX}/lib/X11/xdm/|" \
			${WRKSRC}/config/xdm-config.cpp \
			${WRKSRC}/config/Xstartup.cpp \
			${WRKSRC}/config/Xreset.cpp
	@${REINPLACE_CMD} -e "s|@DESTDIR@||" ${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e "s|${EXAMPLESDIR}|${PREFIX}/lib/X11/xdm|" \
			${WRKSRC}/config.h

post-install:
.for f in ${CFFILES}
	${CP} -n ${EXAMPLESDIR}/$f ${STAGEDIR}${PREFIX}/lib/X11/xdm/$f || ${TRUE}
.endfor
	${MKDIR} /var/lib/xdm/authdir
	${LN} -sf /var/lib/xdm/authdir ${STAGEDIR}${PREFIX}/lib/X11/xdm/authdir

.include <bsd.port.mk>
