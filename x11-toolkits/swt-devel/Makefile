# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swt
DISTVERSION=	3.7.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	ECLIPSE/R-${DISTVERSION}-201109091335
PKGNAMESUFFIX=	-devel
DISTNAME=	swt-${DISTVERSION}-${DIST_EXT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard Widget Toolkit for Java

LICENSE=	EPL

ONLY_FOR_ARCHS=	i386 amd64 powerpc

SWT_VERSION=	3738
OUTPUT_JAR=	${PORTNAME}${PKGNAMESUFFIX}.jar

USE_GL=		yes
USES=		pkgconfig zip
USE_GNOME=	gtk20
USE_JAVA=	yes
JAVA_VERSION=	1.6+
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

OPTIONS_DEFINE=	CAIRO GNOMEVFS MOZILLA
GNOMEVFS_DESC=	Gnome VFS support
MOZILLA_DESC=	Gecko browser support

OPTIONS_DEFAULT=CAIRO GNOMEVFS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	libcairo.so:graphics/cairo
PLIST_FILES+=	lib/libswt-cairo-gtk-%%BUILD%%.so
MAKE_CAIRO=	make_cairo
.endif

.if ${PORT_OPTIONS:MGNOMEVFS}
USE_GNOME+=	gnomevfs2 libgnome libgnomeui
PLIST_FILES+=	lib/libswt-gnome-gtk-%%BUILD%%.so
MAKE_GNOME=	make_gnome
.endif

.if ${PORT_OPTIONS:MMOZILLA}
USES=		gecko
BROKEN=		Does now work with newer libxul
PLIST_FILES+=	lib/libswt-xulrunner-gtk-%%BUILD%%.so
MAKE_MOZILLA=	make_xulrunner
.endif

MAKE_ENV+=	MAKE_CAIRO=${MAKE_CAIRO} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		JAVA_HOME=${JAVA_HOME}

.if (${ARCH} == "amd64")
DIST_EXT=	gtk-linux-x86_64
.elif (${ARCH} == "powerpc")
DIST_EXT=	gtk-linux-ppc64
.else
DIST_EXT=	gtk-linux-x86
.endif

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_NATIVE_CMD} -qo *.zip)
	@${RM} ${WRKSRC}/*.o ${WRKSRC}/*.so ${WRKSRC}/*.jar

post-patch:
	@${SED} -E -e 's|%%ARCH%%|${ARCH}|' \
		-e 's|%%OUTPUT_JAR%%|${OUTPUT_JAR}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${WRKSRC}/libswt-*.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${OUTPUT_JAR} ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
