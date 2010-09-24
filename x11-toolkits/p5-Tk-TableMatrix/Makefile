# New ports collection makefile for:	p5-Tk-TableMatrix
# Date created:			Mon Nov 4 01:15:53 UTC 2002
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-TableMatrix
PORTVERSION=	1.23
PORTREVISION=	4
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Table/matrix extension to perl/tk for displaying table formatted data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
CONFIGURE_ARGS=	X11LIB=${LOCALBASE}/lib X11INC=${LOCALBASE}/include

MAN3=		Tk::TableMatrix.3 \
		Tk::TableMatrix::Spreadsheet.3 \
		Tk::TableMatrix::SpreadsheetHideRows.3

.include <bsd.port.mk>
