# New ports collection makefile for:	swt-devel
# Date created:				2006-11-16
# Whom:					Robert C. Noland III <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	swt-devel
DISTVERSION=	3.6M3
PORTEPOCH=	1
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	S-${DISTVERSION}-200910301201
DISTNAME=	swt-${DISTVERSION}-${DIST_EXT}

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Standard Widget Toolkit for Java

ONLY_FOR_ARCHS=	i386 amd64 ppc

SWT_VERSION=	3617
OUTPUT_JAR=	swt-devel.jar

USE_ZIP=	yes
USE_GL=		yes
USE_GNOME=	gtk20 pkgconfig
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
USE_ANT=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	BUILD=${SWT_VERSION}
PLIST_FILES=	%%JAVAJARDIR%%/${OUTPUT_JAR} \
		lib/libswt-atk-gtk-%%BUILD%%.so \
		lib/libswt-awt-gtk-%%BUILD%%.so \
		lib/libswt-gtk-%%BUILD%%.so \
		lib/libswt-glx-gtk-%%BUILD%%.so \
		lib/libswt-pi-gtk-%%BUILD%%.so

NO_WRKSUBDIR=	yes

OPTIONS=	CAIRO "Cairo Support" on \
		GNOMEVFS "Gnome VFS Support" on \
		BROWSER "Gecko Browser Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_CAIRO)
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
PLIST_FILES+=	lib/libswt-cairo-gtk-%%BUILD%%.so
MAKE_CAIRO=	make_cairo
.endif

.if defined(WITH_GNOMEVFS)
USE_GNOME+=	gnomevfs2 libgnome libgnomeui
PLIST_FILES+=	lib/libswt-gnome-gtk-%%BUILD%%.so
MAKE_GNOME=	make_gnome
.endif

.if defined(WITH_BROWSER)
USE_GECKO=	libxul
PLIST_FILES+=	lib/libswt-xulrunner-gtk-%%BUILD%%.so
MAKE_MOZILLA=	make_xulrunner
.endif

MAKE_ENV+=	MAKE_CAIRO=${MAKE_CAIRO} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		JAVA_HOME=${JAVA_HOME}

.if (${ARCH} == "amd64")
DIST_EXT=	gtk-linux-x86_64
.elif (${ARCH} == "ppc")
DIST_EXT=	gtk-linux-ppc
.else
DIST_EXT=	gtk-linux-x86
.endif

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${RM} -f ${WRKSRC}/*.o ${WRKSRC}/*.so ${WRKSRC}/*.jar

post-patch:
	@${SED} -E -e 's|%%ARCH%%|${ARCH}|' \
		-e 's|%%OUTPUT_JAR%%|${OUTPUT_JAR}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/libswt-*.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${OUTPUT_JAR} ${JAVAJARDIR}/

.include <bsd.port.post.mk>
