# New ports collection makefile for:	wmappl
# Date created:				3 March 2002
# Whom:					od <od@iclub.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmappl
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:main/}
MASTER_SITE_SUBDIR=${PORTNAME}/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

.ifndef(NOICONS)
PATCH_SITES=	http://www.upl.cs.wisc.edu/~charkins/wmappl/
PATCHFILES=	16x16xpms.tar.gz icons_16x16.tar.gz smallicons.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	od@iclub.nsu.ru
COMMENT=	An application launcher dockapp similar to wmbutton

USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_XPM=	yes
MAKE_ENV=	DATADIR="${DATADIR}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

.ifndef(NOICONS)
PLIST_SUB=	ICONS=""
.else
PLIST_SUB=	ICONS="@comment "
.endif

.ifndef(NOICONS)
post-extract:
	@${ECHO_MSG} "===>   Extracting icons ..."
.for icons in ${PATCHFILES}
	@${ECHO_MSG} "===>   ${icons} ..."
	@${TAR} -C ${WRKSRC}/icons -xzf ${DISTDIR}/${icons}
.endfor
	@${MV} ${WRKSRC}/icons/smallicons/* ${WRKSRC}/icons
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmappl ${PREFIX}/bin

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample.wmapplrc ${EXAMPLESDIR}
.ifndef(NOICONS)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "===>   Installing icons to ${DATADIR} directory"
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/icons; ${INSTALL_DATA} *.xpm ${DATADIR})
.endif
.ifndef(NOPORTDOCS)
	@${ECHO_CMD} "===>   Installing README as ${DOCSDIR}/README"
	@${ECHO_CMD} "===>   Please read for configuration information"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${SED} -E 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
