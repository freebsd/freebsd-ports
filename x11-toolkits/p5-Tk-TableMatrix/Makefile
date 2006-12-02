# New ports collection makefile for:	p5-Tk-TableMatrix
# Date created:			Mon Nov 4 01:15:53 UTC 2002
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-TableMatrix
PORTVERSION=	1.22
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Table/matrix extension to perl/tk for displaying table formatted data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	X11LIB=${X11BASE}/lib X11INC=${X11BASE}/include

MAN3=		Tk::TableMatrix.3 \
		Tk::TableMatrix::Spreadsheet.3 \
		Tk::TableMatrix::SpreadsheetHideRows.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
