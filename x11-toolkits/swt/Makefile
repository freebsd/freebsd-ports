# Created by: Robert C. Noland III <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swt
DISTVERSION=	3.5.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits devel java
#MASTER_SITES=	ECLIPSE/R-${DISTVERSION}-201002111343
MASTER_SITES=	http://archive.eclipse.org/eclipse/downloads/drops/R-${DISTVERSION}-201002111343/
DISTNAME=	swt-${DISTVERSION}-${DIST_EXT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard Widget Toolkit for Java

LICENSE=	EPL

ONLY_FOR_ARCHS=	i386 amd64

CONFLICTS=	swt-3.1*

SWT_VERSION=	3557
OUTPUT_JAR=	swt.jar

USE_GL=		yes
USES=		pkgconfig zip:infozip
USE_GNOME=	gtk20
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_ANT=	yes
MAKE_ARGS+=	-Doutput.jar=${OUTPUT_JAR}
MAKEFILE=	make_freebsd.mak
USE_LDCONFIG=	yes
PLIST_SUB=	BUILD=${SWT_VERSION}
PLIST_FILES=	%%JAVAJARDIR%%/${OUTPUT_JAR} \
		lib/libswt-atk-gtk-%%BUILD%%.so \
		lib/libswt-awt-gtk-%%BUILD%%.so \
		lib/libswt-gtk-%%BUILD%%.so \
		lib/libswt-glx-gtk-%%BUILD%%.so \
		lib/libswt-pi-gtk-%%BUILD%%.so

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	CAIRO GNOMEVFS BROWSER
OPTIONS_DEFAULT=	CAIRO GNOMEVFS
GNOMEVFS_DESC=	Gnome VFS Support
BROWSER_DESC=	Gecko Browser Support

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

.if ${PORT_OPTIONS:MBROWSER}
USES=		gecko
BROKEN=		Does not build with newer libxul
PLIST_FILES+=	lib/libswt-xulrunner-gtk-%%BUILD%%.so
MAKE_MOZILLA=	make_xulrunner
.endif

MAKE_ENV+=	MAKE_CAIRO=${MAKE_CAIRO} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		JAVA_HOME=${JAVA_HOME}

.if (${ARCH} == "amd64")
DIST_EXT=	gtk-linux-x86_64
.else
DIST_EXT=	gtk-linux-x86
.endif

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${RM} ${WRKSRC}/*.o ${WRKSRC}/*.so ${WRKSRC}/*.jar

post-patch:
	${SED} -e 's|freebsd|dragonfly|g' ${WRKSRC}/make_freebsd.mak \
		> ${WRKSRC}/make_dragonfly.mak

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${WRKSRC}/libswt-*.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${OUTPUT_JAR} ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
