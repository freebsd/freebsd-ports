# New ports collection makefile for:	p5-Tk-TableMatrix
# Date created:			Mon Nov 4 01:15:53 UTC 2002
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-TableMatrix
PORTVERSION=	0.9
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Table/matrix extension to perl/tk for displaying table formatted data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_SIZE=	yes
PERL_CONFIGURE=	yes

MAN3=		Tk::TableMatrix.3 \
		Tk::TableMatrix::Spreadsheet.3 \
		Tk::TableMatrix::SpreadsheetHideRows.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
