# New ports collection makefile for:	badwm
# Date created:				2002-10-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		badwm
PORTVERSION=		0.06
PORTREVISION=	1
CATEGORIES=		x11-wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		BadWM-${PORTVERSION}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Window manager based on eviwm

DOCDIR=			share/doc/${PORTNAME}
DOCS=		AUTHORS COPYING ChangeLog INSTALL LICENSE README THANKS TODO
PLIST=			${WRKDIR}/pkg-plist
USE_AUTOCONF=		y
WANT_AUTOCONF_VER=	253
USE_GMAKE=		y
USE_X_PREFIX=		y

post-extract:
# Avoid having to audit this huge file.
	${RM} ${WRKSRC}/configure

pre-install:
	${ECHO_CMD} bin/badwm > ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/BadWM ${PREFIX}/bin/badwm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
