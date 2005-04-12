# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.4.2
PORTREVISION?=	8
PKGNAMESUFFIX=	${WXGTK_FLAVOR}
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include \
			  ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv \
			 -L${X11BASE}/lib \
			 ${PTHREAD_LIBS}"
MAKE_ENV=	WXGTK_FLAVOR="${WXGTK_FLAVOR}"
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk

.if ${WXGTK_FLAVOR} != "gtk-common"
RUN_DEPENDS=	${X11BASE}/include/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk-common
.endif

.if ${WXGTK_FLAVOR:M*-common} != ""
NO_BUILD=	yes
INSTALL_TARGET=	install-common
.endif # *-common

.if ${WXGTK_FLAVOR:M*-contrib*} != ""
BUILD_WRKSRC=	${WRKSRC}/contrib/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.if ${WXGTK_FLAVOR} != "gtk-contrib-common"
RUN_DEPENDS=	${X11BASE}/include/wx/stc/stc.h:${PORTSDIR}/x11-toolkits/wxgtk-contrib-common
.if ${WXGTK_FLAVOR} == "gtk-contrib"
LIB_DEPENDS+=	wx_gtk-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk
.elif ${WXGTK_FLAVOR} == "gtk2-contrib"
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
.elif ${WXGTK_FLAVOR} == "gtk2-unicode-contrib"
LIB_DEPENDS+=	wx_gtk2u-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2-unicode
.endif
.endif # !gtk-contrib-common
.endif # *-contrib*

.if ${WXGTK_FLAVOR:Mgtk2*} != ""
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--enable-gtk2 ${MACHINE_ARCH}-portbld-freebsd${OSREL}
.else
USE_GNOME=	gtk12
CONFIGURE_ARGS+=--host=${CONFIGURE_TARGET} --build=${CONFIGURE_TARGET}
.endif

.include <bsd.port.pre.mk>

.if ${WXGTK_FLAVOR:M*-unicode*} != ""
.if ${OSVERSION} < 500000
IGNORE=		Systems prior to FreeBSD 5.0 currently out of support
.endif
CONFIGURE_ARGS+=--enable-unicode
.endif # *-unicode*

pre-patch:
.if ${WXGTK_FLAVOR:Mgtk2*} != ""
	@${REINPLACE_CMD} -e 's|lgdk|lgdk-x11-2.0|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|lgdk|lgdk12|g' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
