# New ports collection makefile for:	p5-Tk400
# Version required:			2.00
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:23:56 jfitz Exp $
#

DISTNAME=	Tk400.200
PKGNAME=	p5-Tk400-2.00
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Tk/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Tk/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Tk/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Tk/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Tk/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Tk/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/HTML/Parse.pm:${PORTSDIR}/www/p5-libwww \
		${PREFIX}/lib/perl5/site_perl/IO.pm:${PORTSDIR}/net/p5-IO
LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Tk::After Tk::Axis Tk::ColorEditor Tk::Dial Tk::DragDrop::Common Tk::DragDrop::SunConst Tk::FileDialog Tk::FileSelect Tk::Font Tk::Ghostscript Tk::HTML::IO Tk::IO Tk::Internals Tk::Parse Tk::ROText Tk::Table Tk::Tcl-perl Tk::TextUndo Tk::UserGuide Tk::WaitBox Tk::pTk blib; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
		@ for file in tkweb; do \
			gzip -9nf ${PREFIX}/man/man1/$$file.1; \
		done
.endif

.include <bsd.port.mk>
