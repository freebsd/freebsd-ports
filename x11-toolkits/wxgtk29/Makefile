# New ports collection makefile for:	wxgtk26
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.6.0
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
PKGNAMESUFFIX=	${WXGTK_FLAVOR}
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png\
		jpeg.9:${PORTSDIR}/graphics/jpeg\
		tiff.4:${PORTSDIR}/graphics/tiff\
		expat.5:${PORTSDIR}/textproc/expat2\
		mspack.1:${PORTSDIR}/archivers/libmspack

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpng=sys\
		--with-libjpeg=sys\
		--with-libtiff=sys\
		--with-zlib=sys\
		--with-expat=sys\
		--with-opengl\
		--with-mspack\
		--with-gtk\
		--disable-backtrace
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			  -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv \
			 -L${X11BASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk2

.if ${WXGTK_FLAVOR} == "gtk2"
CONFLICTS=	wxgtk2-contrib-devel-2.5.2*
.endif

.if ${WXGTK_FLAVOR} != "gtk2-common"
RUN_DEPENDS=	${X11BASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common
.endif

.if ${WXGTK_FLAVOR:M*-common} != ""
NO_BUILD=	yes
INSTALL_TARGET=	install-common
.else
INSTALLS_SHLIB=	yes
.endif # *-common

.if ${WXGTK_FLAVOR:M*-contrib*} != ""
.if ${WXGTK_FLAVOR} != "gtk2-contrib-utils"
BUILD_WRKSRC=	${WRKSRC}/contrib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.if ${WXGTK_FLAVOR} != "gtk2-contrib-common"
RUN_DEPENDS=	${X11BASE}/include/wx-2.6/wx/stc/stc.h:${PORTSDIR}/x11-toolkits/wxgtk26-contrib-common

.if ${WXGTK_FLAVOR:M*-unicode*} != ""
LIB_DEPENDS+=	wx_baseu-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode
.else
LIB_DEPENDS+=	wx_base-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
.endif

pre-configure:
	@${FIND} ${BUILD_WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e "s|@CXXFLAGS@|${CFLAGS} `${WXGTK_CONFIG} --cxxflags`|" \
		-e "s|@CFLAGS@|${CFLAGS} `${WXGTK_CONFIG} --cflags`|" \
		-e "s|@CPPFLAGS@||"

.endif # !gtk2-contrib-common
.endif # !gtk2-contrib-utils
.endif # *-contrib*

.include <bsd.port.pre.mk>

.if ${WXGTK_FLAVOR:M*-unicode*} != ""
.if ${OSVERSION} < 500000
IGNORE=		Systems prior to FreeBSD 5.0 currently out of support
.else
CONFIGURE_ARGS+=--enable-unicode
.endif

WXGTK_CONFIG=	${X11BASE}/bin/wxgtk2u-2.6-config
.else
WXGTK_CONFIG=	${X11BASE}/bin/wxgtk2-2.6-config
.endif # *-unicode*

.include <bsd.port.post.mk>
