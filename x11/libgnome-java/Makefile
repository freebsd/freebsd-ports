# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/libgnome-java/Makefile,v 1.9 2005/10/29 22:06:06 marcus Exp $

PORTNAME=	libgnome-java
PORTVERSION=	2.12.7
PORTREVISION=	6
CATEGORIES=	x11 java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for GNOME 2

DEPRECATED=	Unmaintained, outdated not depend on
EXPIRATION_DATE=	2014-05-25

BUILD_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java
RUN_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java

USES=		dos2unix gmake pathfix pkgconfig shebangfix
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_GNOME=	libgnomeui
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
CONFIGURE_ENV=	ac_cv_path_DB1="nocommand" \
		ac_cv_path_DB2="nocommand"
CPPFLAGS+=	-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
MAKE_JOBS_UNSAFE=	yes
DOS2UNIX_FILES=	gnome2-java.pc.in
SHEBANG_FILES=	doc/examples/runExample.sh.in

# jikes related
CONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

GNOME_API_VERSION=	2.12
GTK_API_VERSION=	2.10
PLIST_SUB=		GNOME_API_VERSION=${GNOME_API_VERSION} PORTNAME=${PORTNAME}

PKGMESSAGE=		${WRKDIR}/pkg-message

post-extract:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/.libs/libgnomejni-${GNOME_API_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libgnomejni-${GNOME_API_VERSION}.so.1
	${LN} -sf libgnomejni-${GNOME_API_VERSION}.so.1 \
		${STAGEDIR}${PREFIX}/lib/libgnomejni-${GNOME_API_VERSION}.so
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/gnome2-java.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/gnome${GNOME_API_VERSION}.jar ${STAGEDIR}${JAVAJARDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/* \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}/tutorial
	${MKDIR} ${STAGEDIR}${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${FIND} . | ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR}/api
	${TOUCH} ${STAGEDIR}${DOCSDIR}/api/packages.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/examples
	cd ${WRKSRC}/doc/examples && ${FIND} . \
		| ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR}/examples
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GNOME_API_VERSION%%|${GNOME_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}

.include <bsd.port.mk>
