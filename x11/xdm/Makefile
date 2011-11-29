# New ports collection makefile for:	xdm
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

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

MAN1=		xdm.1

CFFILES=	GiveConsole TakeConsole Xaccess Xreset Xresources \
		Xservers Xsession Xsetup_0 Xstartup Xwilling xdm-config

OPTIONS=	XDMSHELL "Install xdmshell" off

.include <bsd.port.options.mk>

.if defined(WITH_XDMSHELL)
CONFIGURE_ARGS+=--enable-xdmshell
MAN1+=		xdmshell.1
PLIST_SUB+=	XDMSHELL=""
.else
CONFIGURE_ARGS+=--disable-xdmshell
PLIST_SUB+=	XDMSHELL="@comment "
.endif

post-patch:
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
	${CP} -n ${EXAMPLESDIR}/$f ${PREFIX}/lib/X11/xdm/$f
.endfor
	${MKDIR} /var/lib/xdm/authdir
	${LN} -sf /var/lib/xdm/authdir ${PREFIX}/lib/X11/xdm/authdir

.include <bsd.port.mk>
