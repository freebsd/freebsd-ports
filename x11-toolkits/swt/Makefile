PORTNAME=	swt
DISTVERSION=	4.21
PORTREVISION=	3
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	http://archive.eclipse.org/eclipse/downloads/drops4/R-${DISTVERSION}-202109060500/
DISTNAME=	${PORTNAME}-${DISTVERSION}-gtk-linux-x86_64

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard Widget Toolkit for Java
WWW=		https://www.eclipse.org/swt/

LICENSE=	EPL

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

USES=		compiler:c++11-lang gl gmake gnome java:ant pkgconfig zip:infozip xorg
USE_GL=		glu gl
USE_GNOME=	gdkpixbuf gtk30
USE_XORG=	xtst
JAVA_OS=	native

SWT_VERSION=	4946r21

MAKEFILE=	make_freebsd.mak
MAKE_ENV=	SWT_VERSION=${SWT_VERSION}
PLIST_SUB=	SWT_VERSION=${SWT_VERSION}

NO_SHLIB_REQUIRES_GLOB=	libjawt.so
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	CAIRO WEBKIT
OPTIONS_DEFAULT=	CAIRO
OPTIONS_SUB=	yes

CAIRO_USE=		GNOME=cairo
CAIRO_MAKE_ENV=		MAKE_CAIRO=make_cairo

WEBKIT_IMPLIES=		CAIRO
WEBKIT_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk@40
WEBKIT_MAKE_ENV=	BUILD_WEBKIT2EXTENSION=yes
WEBKIT_MAKE_ENV_OFF=	BUILD_WEBKIT2EXTENSION=no

.include <bsd.port.pre.mk>

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}/build.xml
	@${CP} ${WRKSRC}/make_linux.mak ${WRKSRC}/make_freebsd.mak
	@${CP} ${FILESDIR}/*.css ${WRKSRC}/org/eclipse/swt/internal/gtk/

post-patch:
.if ${OPSYS} == FreeBSD
	${REINPLACE_CMD} -e 's|-DGTK|-DGTK -Wno-error=deprecated-non-prototype|g' \
		${WRKSRC}/make_freebsd.mak
.endif
	${SED} -e 's|freebsd|dragonfly|g' ${WRKSRC}/make_freebsd.mak \
		> ${WRKSRC}/make_dragonfly.mak

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${WRKSRC}/libswt-*.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/swt.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.post.mk>
