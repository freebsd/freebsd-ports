# New ports collection makefile for:	p5-Tk-FileDialog
# Date created:		1 July 2001
# Whom:			minter
#
# $FreeBSD$

PORTNAME=	Tk-FileDialog
PORTVERSION=	1.3
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk

MAINTAINER=	minter@lunenburg.org
COMMENT=	Tk::FileDialog - A file selector dialog for perl/Tk

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes
MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Tk::FileDialog.3

PLIST_SUB=	PERL_VERSION=${PERL_VERSION}

.include <bsd.port.mk>
