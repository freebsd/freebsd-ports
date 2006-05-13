# New ports collection makefile for:	swt
# Date created:				2005-12-15
# Whom:					past@ebs.gr
#
# $FreeBSD$
#

PORTNAME=	swt
PORTVERSION=	3.1.1
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200509290840

MAINTAINER=	freebsd-eclipse@freebsd.org
COMMENT=	Standard Widget Toolkit for Java

SWT_VERSION=	3139
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
MAKEFILE=	make_freebsd.mak
INSTALLS_SHLIB=	yes
PLIST_SUB=	BUILD=${SWT_VERSION}
PLIST_FILES=	%%JAVAJARDIR%%/swt.jar \
		lib/libswt-atk-gtk-%%BUILD%%.so \
		lib/libswt-awt-gtk-%%BUILD%%.so \
		lib/libswt-gtk-%%BUILD%%.so \
		lib/libswt-pi-gtk-%%BUILD%%.so

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
USE_GNOME=	gtk20 pkgconfig
.else
MAKE_GNOME=	make_gnome
USE_GNOME=	gtk20 gnomevfs2 libgnome libgnomeui pkgconfig
PLIST_FILES+=	lib/libswt-gnome-gtk-%%BUILD%%.so
.endif

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
DISTNAME=	swt-${PORTVERSION}-gtk-linux-x86_64
WITHOUT_CAIRO=	yes
.else
DISTNAME=	swt-${PORTVERSION}-gtk-linux-x86
.endif

.if !defined(WITHOUT_MOZILLA)
PLIST_FILES+=	lib/libswt-mozilla-gtk-%%BUILD%%.so
MAKE_MOZILLA=	make_mozilla
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA} != "mozilla"
BROWSER=	${WITH_MOZILLA}
BUILD_DEPENDS+=	${BROWSER}:${PORTSDIR}/www/${BROWSER}
.else
BUILD_DEPENDS+=	mozilla:${PORTSDIR}/www/mozilla
BROWSER=	mozilla
.endif
.else
BROWSER=
MAKE_MOZILLA=
.endif

.if defined(WITHOUT_CAIRO)
MAKE_CAIRO=
.else
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
PLIST_FILES+=	lib/libswt-cairo-gtk-%%BUILD%%.so
.endif

MAKE_ENV+=	BROWSER="${BROWSER}" \
		JAVA_HOME="${JAVA_HOME}" \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		MAKE_CAIRO=${MAKE_CAIRO} \
		MACHINE_ARCH=${MACHINE_ARCH}

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${CP} ${WRKSRC}/make_linux.mak ${WRKSRC}/make_freebsd.mak

post-patch:
	@${RM} ${WRKSRC}/lib*.so
.if (${ARCH} != "amd64")
	@${PATCH} ${PATCH_DIST_ARGS} \
	  "cairo.c" \
	  ${FILESDIR}/manualpatch-cairo \
	  + "cairo.h" \
	  + "cairo_custom.c" \
	  + "cairo_stats.c" \
	  + "cairo_stats.h" \
	  + "cairo_structs.c" \
	  + "cairo_structs.h"
.endif
	@${REINPLACE_CMD} -E \
		-e 's|%%CC%%|${CC}|' \
		-e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/build.sh

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.sh)

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/libswt-*.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/swt.jar ${JAVAJARDIR}/

.include <bsd.port.post.mk>
