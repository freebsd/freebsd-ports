# New ports collection makefile for:	wxgtk26
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.6.4
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/wxGTK/${PORTVERSION}
PKGNAMESUFFIX=	${WXGTK_FLAVOR}
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png\
		jpeg.10:${PORTSDIR}/graphics/jpeg\
		tiff.4:${PORTSDIR}/graphics/tiff\
		expat.6:${PORTSDIR}/textproc/expat2\
		mspack.1:${PORTSDIR}/archivers/libmspack

USE_BZIP2=	yes
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		glu
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	gtk20
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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"\
		X11BASE="${LOCALBASE}"
NO_LATEST_LINK=	yes
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk2

.if ${WXGTK_FLAVOR} == "gtk2"
CONFLICTS=	wxgtk2-contrib-devel-2.5.2*
.endif

.if ${WXGTK_FLAVOR} != "gtk2-common"
RUN_DEPENDS=	${LOCALBASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common
.endif

.if ${WXGTK_FLAVOR:M*-common} != ""
NO_BUILD=	yes
INSTALL_TARGET=	install-common
.else
USE_LDCONFIG=	yes
.endif # *-common

.if ${WXGTK_FLAVOR:M*-contrib*} != ""
BUILD_WRKSRC=	${WRKSRC}/contrib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.if ${WXGTK_FLAVOR} != "gtk2-contrib-common"
USE_WX=		2.6
RUN_DEPENDS=	${LOCALBASE}/include/wx-2.6/wx/stc/stc.h:${PORTSDIR}/x11-toolkits/wxgtk26-contrib-common

.if ${WXGTK_FLAVOR:M*-unicode*} != ""
WX_UNICODE=	yes
.endif

pre-configure:
	@${FIND} ${BUILD_WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e "s|@CXXFLAGS@|${CFLAGS} `${WX_CONFIG} --cxxflags`|" \
		-e "s|@CFLAGS@|${CFLAGS} `${WX_CONFIG} --cflags`|" \
		-e "s|@CPPFLAGS@||"

.endif # !gtk2-contrib-common
.endif # *-contrib*

.if ${WXGTK_FLAVOR:M*-unicode*} != ""
CONFIGURE_ARGS+=--enable-unicode
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_config_args --cflags|pkg_config_args pangox --cflags|g ; \
		s|pkg_config_args --libs|pkg_config_args pangox --libs|g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
