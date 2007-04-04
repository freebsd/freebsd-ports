# New ports collection makefile for:	swt-devel
# Date created:				2006-11-16
# Whom:					Robert C. Noland III <rnoland@2hip.net>
#
# $FreeBSD$
#

PORTNAME=	swt-devel
PORTVERSION=	3.3M6
CATEGORIES=	x11-toolkits devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	S-${PORTVERSION}-200703231616
DISTNAME=	swt-${PORTVERSION}-${DIST_EXT}

MAINTAINER=	rnoland@2hip.net
COMMENT=	Standard Widget Toolkit for Java

ONLY_FOR_ARCHS=	i386 amd64

SWT_VERSION=	3333
OUTPUT_JAR=	swt-devel.jar

USE_ZIP=	yes
USE_GL=		yes
USE_GNOME=	gtk20 pkgconfig
USE_JAVA=	yes
JAVA_VERSION=	1.4+
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
USE_GECKO=	mozilla firefox seamonkey

.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

PLIST_FILES+=	lib/libswt-${GECKO}-gtk-%%BUILD%%.so
MAKE_MOZILLA=	make_mozilla
.endif

MAKE_ENV+=	MAKE_CAIRO=${MAKE_CAIRO} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA}

.if (${ARCH} == "amd64")
DIST_EXT=	gtk-linux-x86_64
.else
DIST_EXT=	gtk-linux-x86
.endif

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo "*.zip")
	@${RM} -f ${WRKSRC}/*.o ${WRKSRC}/*.so ${WRKSRC}/*.jar

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-|${GECKO}-|' \
		${WRKSRC}/build.sh
	@${REINPLACE_CMD} -e 's|swt-mozilla|swt-${GECKO}|' \
		${WRKSRC}/make_freebsd.mak

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/libswt-*.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${OUTPUT_JAR} ${JAVAJARDIR}/

.include <bsd.port.post.mk>
