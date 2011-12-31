# New ports collection makefile for:   trayer-srg
# Date created:	Jun 21, 2011
# Whom:		Guido Falsi <mad@madpilot.net>
# Based on the x11/trayer port Makefile from Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	trayer
PORTVERSION=	1.1.4
CATEGORIES=	x11
MASTER_SITES=	http://github.com/sargon/${PORTNAME}${PKGNAMESUFFIX}/tarball/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	-srg
DISTNAME=	sargon-${PORTNAME}${PKGNAMESUFFIX}-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	mad@madpilot.net
COMMENT=	Lightweight GTK2-based systray for UNIX desktop - sargon fork

CONFLICTS_INSTALL=	trayer-1.0*
GITVERSION=	0-g412ad31
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/sargon-${PORTNAME}${PKGNAMESUFFIX}-${GITVERSION:S/^0-g//}
USE_GNOME=	gtk20 glib20 pango atk
USE_ICONV=	yes
USE_XORG=	xmu
USE_GMAKE=	yes
MAKE_ARGS=	"PREFIX=${PREFIX}"

.if !defined(NOPORTDOCS)
PORTDOCS=	README CREDITS CHANGELOG
.endif

PLIST_FILES=	bin/trayer

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
