# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swt
DISTVERSION=	4.7.3a
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	https://archive.eclipse.org/eclipse/downloads/drops4/R-${DISTVERSION}-201803300640/
DISTNAME=	${DISTNAME_${ARCH}}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Standard Widget Toolkit for Java

LICENSE=	EPL

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le

USES=		compiler:c++11-lang gl gnome pkgconfig zip:infozip xorg

USE_ANT=	yes
USE_GL=		glu gl
USE_GNOME=	gtk20
USE_JAVA=	yes
USE_XORG=	xtst
JAVA_OS=	native

SWT_VERSION=	4763

MAKEFILE=	make_freebsd.mak

PLIST_FILES=	${JAVAJARDIR}/swt.jar \
		lib/libswt-atk-gtk-${SWT_VERSION}.so \
		lib/libswt-awt-gtk-${SWT_VERSION}.so \
		lib/libswt-gtk-${SWT_VERSION}.so \
		lib/libswt-glx-gtk-${SWT_VERSION}.so \
		lib/libswt-pi-gtk-${SWT_VERSION}.so

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	CAIRO
OPTIONS_DEFAULT=	CAIRO

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_PLIST_FILES=	lib/libswt-cairo-gtk-${SWT_VERSION}.so
CAIRO_MAKE_ENV=		MAKE_CAIRO=make_cairo

DISTNAME_aarch64=	${PORTNAME}-${DISTVERSION}-gtk-linux-x86_64
DISTNAME_amd64=		${PORTNAME}-${DISTVERSION}-gtk-linux-x86_64
DISTNAME_i386=		${PORTNAME}-${DISTVERSION}-gtk-linux-x86
# The source code for x86_64 and ppc64 is identical, so prefer x86_64 tarball
# to save space and time
DISTNAME_powerpc64=	${PORTNAME}-${DISTVERSION}-gtk-linux-x86_64
DISTNAME_powerpc64le=	${PORTNAME}-${DISTVERSION}-gtk-linux-x86_64

.if ${.TARGETS:Mmakesum}
. for i in ${ONLY_FOR_ARCHS}
DISTFILES:=	${DISTNAME_${i}}${EXTRACT_SUFX} ${DISTFILES}
. endfor
.endif

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${RM} ${WRKSRC}/*.o ${WRKSRC}/*.so ${WRKSRC}/*.jar
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}/build.xml

post-patch:
	${SED} -e 's|freebsd|dragonfly|g' ${WRKSRC}/make_freebsd.mak \
		> ${WRKSRC}/make_dragonfly.mak

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${WRKSRC}/libswt-*.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/swt.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
